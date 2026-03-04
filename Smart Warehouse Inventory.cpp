// Smart Warehouse Inventory.cpp

#include <iostream>
using namespace std;

enum SlotStatus
{
    EMPTY, OCCUPIED, RESERVED
};

class WarehouseSystem
{
private:
    int shelf_units[4][5];
    SlotStatus slot_status[4][5];
    int shipped_units_per_day[7];
    int total_units_in_warehouse;

public:
    WarehouseSystem()
    {
        for (int row = 0; row < 4; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                shelf_units[row][col] = 0;
                slot_status[row][col] = EMPTY;
            }
        }
        for (int day = 0; day < 7; day++)
        {
            shipped_units_per_day[day] = 0;
        }
        total_units_in_warehouse = 0;
    }

    void display_shelf_map()
    {
        for (int row = 0; row < 4; row++)
        {
            cout << "Row " << row + 1 << ": ";
            for (int col = 0; col < 5; col++)
            {
                switch (slot_status[row][col])
                {
                    case EMPTY:
                    {
                        cout << "E ";
                        break;
                    }
                        
                    case OCCUPIED:
                    {
                        cout << "O ";
                        break;
                    }

                    case RESERVED:
                    {
                        cout << "R ";
                        break;
                    }

                    default:
                    {
                        cout << "_ ";
                        break;
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }

    void reserve_slot(int row, int col)
    {
        if (row >= 0 && row <= 3 && col >= 0 && col <= 4)
        {
            if (slot_status[row][col] == EMPTY)
            {
                slot_status[row][col] = RESERVED;
                cout << "Slot reserved successfully!" << endl;
            }
            else
            {
                cout << "Cannot reserve. Slot is not empty." << endl;
            }
        }
        else
        {
            cout << "Invalid Row and/or Column." << endl;
        }
        cout << endl;
    }

    void add_stock(int row, int col, int units)
    {
        if (row >= 0 && row <= 3 && col >= 0 && col <= 4 && units > 0)
        {
            if (slot_status[row][col] == EMPTY || slot_status[row][col] == RESERVED)
            {
                shelf_units[row][col] = units;
                slot_status[row][col] = OCCUPIED;
                total_units_in_warehouse += units;
            }
        }
        else
        {
            cout << "Invalid Input(s)." << endl;
        }
    }

    void ship_stock(int row, int col, int units, int day_number)
    {
        if (row >= 0 && row <= 3 && col >= 0 && col <= 4 && units > 0 && units <= shelf_units[row][col] && day_number >= 1 && day_number <= 7)
        {
            if (slot_status[row][col] == OCCUPIED)
            {
                shelf_units[row][col] -= units;
                total_units_in_warehouse -= units;
                shipped_units_per_day[day_number - 1] += units;

                if (shelf_units[row][col] == 0)
                {
                    slot_status[row][col] = EMPTY;
                }
            }
            else
            {
                cout << "Cannot ship. Slot is not occupied." << endl;
            }
        }
        else
        {
            cout << "Invalid Input(s)." << endl;
        }
    }

    void display_weekly_shipping_report()
    {
        int total = 0;
        for (int day = 0; day < 7; day++)
        {
            cout << "Day " << day + 1 << ": " << shipped_units_per_day[day] << endl;
            total += shipped_units_per_day[day];
        }
        cout << "Total Units Shipped: " << total << endl << endl;
    }

    void find_best_shipping_day()
    {
        int max_day = 0;
        for (int day = 0; day < 7; day++)
        {
            if (shipped_units_per_day[day] > shipped_units_per_day[max_day])
            {
                max_day = day;
            }
        }
        cout << "Best Shipping Day: " << max_day + 1 << endl;
        cout << "Units Shipped: " << shipped_units_per_day[max_day] << endl << endl;
    }
};

int main()
{
    WarehouseSystem warehouse;

    warehouse.display_shelf_map();

    warehouse.reserve_slot(0, 2);
    warehouse.add_stock(0, 2, 50);

    warehouse.add_stock(1, 1, 30);
    warehouse.add_stock(2, 4, 20);

    warehouse.ship_stock(0, 2, 10, 1);
    warehouse.ship_stock(1, 1, 15, 4);

    warehouse.display_shelf_map();
    warehouse.display_weekly_shipping_report();
    warehouse.find_best_shipping_day();

    return 0;
}