/*  Smart Transit Card.cpp
    Samuel Holmes - 11/11/2025  */


#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


// Global Variable Declaration
float globalBalance = 0;
bool in_Trip = false;
int currentStartZone = 0;
int currentStartHour = 0;
int lastStartZone = 0;
int lastStartHour = 0;
int lastEndZone = 0;
int lastEndHour = 0;
float lastFare = 0;


// Function Declaration
int getValidEntry(int userEntry);
void rechargeAccount();
void tap_in();
void tap_out();
float computeFare(int startHour, int startZone, int endHour, int endZone);
void showBalance();
void showLastTrip();
void adminDebug();


// Main Function
int main()
{
    int userEntry = 0;

    do {
        
        userEntry = getValidEntry(userEntry);

        switch (userEntry)
        {
            case 1:
            {
                rechargeAccount();
                break;
            }
            case 2:
            {
                tap_in();
                break;
            }
            case 3:
            {
                tap_out();
                break;
            }
            case 4:
            {
                showBalance();
                break;
            }
            case 5:
            {
                showLastTrip();
                break;
            }
            case 6:
            {
                adminDebug();
                break;
            }
            case 7:
            {
                break;
            }
            default:
            {
                return 0;
            }
        }

    } while (userEntry != 7);

    cout << endl << "Exited Successfully" << endl;
    return 0;
}

// Functions
int getValidEntry(int userEntry)
{
    int input = 0;

    cout << "=== SMART TRANSIT CARD ===" << endl;
    cout << "1) Recharge"       << endl;
    cout << "2) Tap-In"         << endl;
    cout << "3) Tap-Out"        << endl;
    cout << "4) Show Balance"   << endl;
    cout << "5) Show Last Trip" << endl;
    cout << "6) Admin/Debug"    << endl;
    cout << "7) Exit"           << endl;
    cout << "Choose: ";

    cin >> input;

    while (input < 1 || input > 7)
    {
        cout << "Invalid Entry. Try again: ";
        cin >> input;
    }

    return input;
}

void rechargeAccount()
{
    float amount = 0;
    cout << "Enter recharge amount: ";
    cin >> amount;

    while (amount <= 0)
    {
        cout << "Invalid Entry.Try again: ";
        cin >> amount;
    }

    // Amount must follow $XX.XX format. Ex: Can be 10 or 10.25, but not 10.333
    amount = int(amount * 100) / 100.00;


    globalBalance += amount;
    cout << "Recharge successful. New balance: $" << fixed << setprecision(2) << globalBalance << endl << endl;
}

void tap_in()
{
    if (in_Trip)
    {
        cout << "You are already in a trip. Please tap out first" << endl;
    }
    else
    {
        cout << "Enter starting zone (1-3): ";
        cin >> currentStartZone;
        while (currentStartZone < 1 || currentStartZone > 3)
        {
            cout << "Invalid Entry. Try again: ";
            cin >> currentStartZone;
        }

        cout << "Enter start hour (0-23): ";
        cin >> currentStartHour;
        while (currentStartHour < 0 || currentStartHour > 23)
        {
            cout << "Invalid Entry. Try again: ";
            cin >> currentStartHour;
        }

        in_Trip = true;
        cout << "Tap-In recorded successfully" << endl << endl;
    }
}

void tap_out()
{
    if (!in_Trip)
    {
        cout << "You are not currently in a trip" << endl;
        while (globalBalance < 6)
        {
            cout << "Insufficient balance. Please recharge now." << endl;
            rechargeAccount();
        }

        cout << "Penalty charged: $6.00" << endl;
        globalBalance -= 6;
        cout << "Remaining balance: $" << fixed << setprecision(2) << globalBalance << endl << endl;
    }
    else
    {
        // Getting Stats
        lastStartHour = currentStartHour;
        lastStartZone = currentStartZone;

        cout << "Enter ending zone (1-3): ";
        cin >> lastEndZone;
        while (lastEndZone < 1 || lastEndZone > 3)
        {
            cout << "Invalid Entry. Try again: ";
            cin >> lastEndZone;
        }

        cout << "Enter ending hour (0-23): ";
        cin >> lastEndHour;
        while (lastEndHour < 0 || lastEndHour > 23)
        {
            cout << "Invalid Entry. Try again: ";
            cin >> lastEndHour;
        }

        // Calculating Fare
        lastFare = computeFare(lastStartHour, lastStartZone, lastEndHour, lastEndZone);
        while (globalBalance < lastFare)
        {
            cout << "Insufficient balance. Please recharge now." << endl;
            rechargeAccount();
        }

        cout << "Trip completed. Fare: $" << fixed << setprecision(2) << lastFare << endl;
        globalBalance -= lastFare;
        cout << "Remaining balance: $" << fixed << setprecision(2) << globalBalance << endl << endl;

        in_Trip = false;
    }
}

float computeFare(int startHour, int startZone, int endHour, int endZone)
{
    // Base Fare
    float fare = 2.5;

    // Peak Hour Bonus
    if ((startHour >= 7 && startHour <= 9) || (startHour >= 17 && startHour <= 19))
    {
        fare += 1.25;
    }
    else if ((endHour >= 7 && endHour <= 9) || (endHour >= 17 && endHour <= 19))
    {
        fare += 1.25;
    }

    // Cross Zone Bonus
    if (startZone != endZone)
    {
        fare += 1.75;
    }

    return fare;
}

void showBalance()
{
    cout << "Your current balance is: $" << fixed << setprecision(2) << globalBalance << endl << endl;
}

void showLastTrip()
{
    /* The variable lastFare starts at Zero. However, once the first trip is completed, it is no longer Zero.
    This way, we know if a trip has been completed yet  */

    if (lastFare == 0)
    {
        cout << "No previous trip found" << endl << endl;
    }
    else
    {
        cout << "\n=== Last Trip Summary ===" << endl;
        cout << "Start Zone: " << lastStartZone << endl;
        cout << "End Zone: " << lastEndZone << endl;
        cout << "Start Hour: " << lastStartHour << endl;
        cout << "End Hour: " << lastEndHour << endl;
        cout << "Fare Paid: $" << lastFare << endl << endl;
    }
}

void adminDebug()
{
    float* ptr_globalBalance = &globalBalance;
    bool* ptr_in_Trip = &in_Trip;
    int* ptr_startZone = &lastStartZone;
    int* ptr_startHour = &lastStartHour;
    int* ptr_endZone = &lastEndZone;
    int* ptr_endHour = &lastEndHour;

    cout << "[ADMIN DEBUG]" << endl;
    cout << "globalBalance @ "  << ptr_globalBalance    << " = " << *ptr_globalBalance  << endl;
    cout << "in_Trip @ "        << ptr_in_Trip          << " = " << *ptr_in_Trip        << endl;
    cout << "lastStartZone @ "  << ptr_startZone        << " = " << *ptr_startZone      << endl;
    cout << "lastEndZone @ "    << ptr_endZone          << " = " << *ptr_endZone        << endl;
    cout << "lastStartHour @ "  << ptr_startHour        << " = " << *ptr_startHour      << endl;
    cout << "lastEndHour @ "    << ptr_endHour          << " = " << *ptr_endHour        << endl << endl;
}