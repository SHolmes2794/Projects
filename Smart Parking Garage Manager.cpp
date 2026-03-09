// Smart Parking Garage Manager.cpp
// Samuel Holmes        Last Updated: 3/9/2026

#include <iostream>
using namespace std;

// ------------------
//        ENUM       
// ------------------
enum SpotStatus
{
    EMPTY, OCCUPIED, RESERVED
};

// -------------------
//      FUNCTIONS        
// -------------------
char status_to_char(SpotStatus s)
{
    if (s == EMPTY)
    {
        return 'E';
    }
    else if (s == OCCUPIED)
    {
        return 'O';
    }
    else
    {
        return 'R';
    }
}

void print_garage_map(const SpotStatus garage[3][4])
{
    cout << "===== Garage Map =====" << endl;

    for (int floor = 0; floor < 3; floor++)
    {
        for (int spot = 0; spot < 4; spot++)
        {
            cout << status_to_char(garage[floor][spot]) << " ";
        }
        cout << endl;
    }

    cout << endl;
}

int count_empty_spots(const SpotStatus garage[3][4])
{
    int number_of_empty_spots = 0;
    for (int floor = 0; floor < 3; floor++)
    {
        for (int spot = 0; spot < 4; spot++)
        {
            if (garage[floor][spot] == EMPTY)
            {
                number_of_empty_spots++;
            }
        }
    }
    
    return number_of_empty_spots;
}

// -------------------
//        CLASS       
// -------------------
class ParkingGarage
{
    private:
        SpotStatus garage[3][4];
        int parked_count[3];

    public:
        ParkingGarage()
        {
            // Set All Spots to EMPTY
            for (int floor = 0; floor < 3; floor++)
            {
                for (int spot = 0; spot < 4; spot++)
                {
                    garage[floor][spot] = EMPTY;
                }
            }

            // Set All Parked_Count Values to 0
            for (int floor = 0; floor < 3; floor++)
            {
                parked_count[floor] = 0;
            }

            // Special Rule: Floor 0, Spot 0 is RESERVED
            garage[0][0] = RESERVED;
        }

        bool set_spot_status(int floor, int spot, SpotStatus new_status)
        {
            // Must Be Valid Location
            if (floor < 0 || floor > 2 || spot < 0 || spot > 3)
            {
                cout << "Location Does Not Exist!" << endl;
                return false;
            }
            
            // Special Rule: Floor 0, Spot 0 is RESERVED
            if (floor == 0 && spot == 0)
            {
                cout << "Floor 0, Spot 0 is Permanently Reserved!" << endl;
                return false;
            }

            SpotStatus current_status = garage[floor][spot];

            // Change Status (if possible) and Update parked_count (if needed)
            switch (new_status)
            {
                case OCCUPIED:
                {
                    if (current_status == EMPTY)
                    {
                        cout << "Successful Parking!" << endl;
                        garage[floor][spot] = OCCUPIED;
                        parked_count[floor]++;
                        return true;
                    }
                    else
                    {
                        cout << "Cannot Park Here!" << endl;
                        return false;
                    }
                }
                
                case EMPTY:
                {
                    if (current_status == OCCUPIED)
                    {
                        cout << "Successfully Left!" << endl;
                        garage[floor][spot] = EMPTY;
                        parked_count[floor]--;
                        return true;
                    }
                    else
                    {
                        cout << "Cannot Leave From Here!" << endl;
                        return false;
                    }
                }

                case RESERVED:
                {
                    if (current_status == EMPTY)
                    {
                        cout << "Successfully Reserved!" << endl;
                        garage[floor][spot] = RESERVED;
                        return true;
                    }
                    else
                    {
                        cout << "Cannot Reserve Here!" << endl;
                        return false;
                    }
                }

                default:
                {
                    return false;
                }
            }
        }

        SpotStatus get_spot_status(int floor, int spot)
        {
            return garage[floor][spot];
        }

        int get_parked_count(int floor)
        {
            int parked_amount = 0;
            for (int spot = 0; spot < 4; spot++)
            {
                if (garage[floor][spot] == OCCUPIED)
                {
                    parked_amount++;
                }
            }
            return parked_amount;
        }

        void print_map()
        {
            print_garage_map(garage);
        }

        int total_empty_spots()
        {
            return count_empty_spots(garage);
        }
};

// ------------------
//        MAIN       
// ------------------
int main()
{
    ParkingGarage garage_system;

    int n;
    cout << "Enter Number of Operations: ";
    cin >> n;

    // Conduct n Operations
    cout << "\nKey: 'P' == Park a Car, 'L' == Leave a Spot, 'R' == Reserve a Spot" << endl;
    cout << "Enter: Operation Floor Spot" << endl << endl;
    for (int index = 0; index < n; index++)
    {
        char op;
        int floor;
        int spot;

        cin >> op >> floor >> spot;

        // P == Park a Car
        if (op == 'P' || op == 'p')
        {
            garage_system.set_spot_status(floor, spot, OCCUPIED);
        }

        // L = Leave a Spot
        else if (op == 'L' || op == 'l')
        {
            garage_system.set_spot_status(floor, spot, EMPTY);
        }

        // R == Reserve a Spot
        else if (op == 'R' || op == 'r')
        {
            garage_system.set_spot_status(floor, spot, RESERVED);
        }

        else
        {
            cout << "Invalid Operation!" << endl;
        }

        cout << endl;
    }

    // Print Garage
    cout << endl;
    garage_system.print_map();

    // Print Parked Count
    cout << "Parked Count Per Floor: " << endl;
    for (int floor = 0; floor < 3; floor++)
    {
        cout << "Floor " << floor << ": " << garage_system.get_parked_count(floor) << endl;
    }
    cout << endl;

    // Print Empty Count
    cout << "Total Empty Spots: " << garage_system.total_empty_spots() << endl;

    return 0;
}