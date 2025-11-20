/*  SCTS.cpp - Smart City Transportation Simulator
    Samuel Holmes           Last Updated: 11/20/2025      */


#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;


// Function Declarations
void mainMenu(int* ptr_Choice);
void rechargeSmartPass(double* ptr_Balance);
void planJourney(double* ptr_Balance);
double computeJourneyFare(int startZone, int endZone, int travelHour, int travelMode);
void simulateTraffic();
void displayCityMap();


// Main Function
int main()
{
    srand(time(0));

    int userInput = 1;
    double balance = 0.0;

    do
    {
        mainMenu(&userInput);

        switch (userInput)
        {
            case 1:
            {
                rechargeSmartPass(&balance);
                break;
            }
            case 2:
            {
                planJourney(&balance);
                break;
            }
            case 3:
            {
                simulateTraffic();
                break;
            }
            case 4:
            {
                displayCityMap();
                break;
            }
            case 5:
            {
                break;
            }
            default:
            {
                return 0;
            }
        }

        cout << endl;

    } while (userInput != 5);


    return 0;
}


// Function Definitions
void mainMenu(int* ptr_Choice)
{
    // Menu Display
    cout << "====================================" << endl;
    cout << "   SMART  CITY  TRANSPORT  SYSTEM   " << endl; 
    cout << "====================================" << endl;
    cout << "1. Recharge Smart-Pass" << endl;
    cout << "2. Plan a Journey" << endl;
    cout << "3. Simulate Traffic" << endl;
    cout << "4. View City Map" << endl;
    cout << "5. Exit" << endl;
    cout << "   Enter your choice: ";

    // Gets and Verifies Input
    int input;
    cin >> input;

    while (input < 1 || input > 5)
    {
        cout << "   Invalid Entry. Enter your choice: ";
        cin >> input;
    }

    // Updates userInput
    *ptr_Choice = input;
}

void rechargeSmartPass(double* ptr_Balance)
{
    // Display
    cout << endl << "------------------------------------" << endl;
    cout << "Input Recharge Amount : $";

    // Gets and Verifies Input
    double rechargeAmount;
    cin >> rechargeAmount;

    while (rechargeAmount < 5)
    {
        cout << "Invalid Entry. Enter your choice: ";
        cin >> rechargeAmount;
    }

    // Amount must follow $XX.XX format. Ex: Can be 10 or 10.25, but not 10.333
    double temp = rechargeAmount;
    rechargeAmount = int(rechargeAmount * 100) / 100.00;
    if (temp != rechargeAmount)
    {
        cout << "Input converted to $" << rechargeAmount << endl;
    }

    // Apply 10% Bonus if Possible
    if (rechargeAmount >= 50)
    {
        rechargeAmount += rechargeAmount * .1;
    }

    // Updates balance and reports change
    cout << "Old Balance: $" << fixed << setprecision(2) << *ptr_Balance << endl;
    *ptr_Balance += rechargeAmount;
    cout << "New Balance: $" << fixed << setprecision(2) << *ptr_Balance << endl;

    cout << "------------------------------------" << endl;
}

void planJourney(double* ptr_Balance)
{
    // Display
    cout << endl << "------------------------------------" << endl;

    // Gets and Verifies Inputs
    int startZone, endZone, travelHour, travelMode;

    cout << "Input Start Zone (1-5): ";
    cin >> startZone;
    while (startZone < 1 || startZone > 5)
    {
        cout << "Invalid Entry. Enter your choice: ";
        cin >> startZone;
    }

    cout << "Input End Zone (1-5): ";
    cin >> endZone;
    while (endZone < 1 || endZone > 5)
    {
        cout << "Invalid Entry. Enter your choice: ";
        cin >> endZone;
    }

    cout << "Input Travel Hour (0-23): ";
    cin >> travelHour;
    while (travelHour < 0 || travelHour > 23)
    {
        cout << "Invalid Entry. Enter your choice: ";
        cin >> travelHour;
    }

    cout << "Input Travel Mode (1=Bus, 2=Taxi, 3=Metro): ";
    cin >> travelMode;
    while (travelMode < 1 || travelMode > 3)
    {
        cout << "Invalid Entry. Enter your choice: ";
        cin >> travelMode;
    }

    // Computes Fare
    double fare = computeJourneyFare(startZone, endZone, travelHour, travelMode);

    // Payment
    cout << "\nPay with pass? (1 = Yes, 0 = No): ";
    int pay_with_pass;
    cin >> pay_with_pass;

    while (pay_with_pass != 0 && pay_with_pass != 1)
    {
        cout << "Invalid Entry. Enter your choice: ";
        cin >> pay_with_pass;
    }

    if (pay_with_pass == 0)
    {
        cout << "Please pay $" << fixed << setprecision(2) << fare << " in cash." << endl;
    }
    else
    {
        if (*ptr_Balance < fare)
        {
            cout << "Insufficient Balance. Please recharge Smart-Pass." << endl;
            rechargeSmartPass(ptr_Balance);
        }
        
        *ptr_Balance -= fare;
        cout << "\nFare: $" << fixed << setprecision(2) << fare << endl;
        cout << "New Balance: $" << fixed << setprecision(2) << *ptr_Balance << endl;
    }

    // Safety Message if Needed
    if (abs(endZone - startZone) > 2 && travelHour >= 22)
    {
        cout << "Long-distance night travel. Please be cautious." << endl;
    }

    cout << "------------------------------------" << endl;
}

double computeJourneyFare(int startZone, int endZone, int travelHour, int travelMode)
{
    double fare = 0.0;
    int zoneDistance = abs(endZone - startZone);

    // Basic Fare Costs
    if (travelMode == 1)    // Bus
    {
        fare = 2.0 + zoneDistance * 1.0;
    }
    else if (travelMode == 2)   // Taxi
    {
        fare = 3.0 + zoneDistance * 2.0;
    }   
    else   // Metro
    {
        fare = 2.5 + zoneDistance * 1.5;
    }

    // Peak Hours Costs
    if ((travelHour >= 7 && travelHour <= 10) || (travelHour >= 17 && travelHour <= 20))
    {
        fare *= 1.25;
    }

    return fare;
}

void simulateTraffic()
{
    int trafficDensity = rand() % 101;
    int accidentRisk = rand() % 11;
    int weather = 1 + rand() % 5;

    // Display
    cout << endl << "------------------------------------" << endl;

    if (accidentRisk >= 8)
    {
        cout << "Proceed With Caution" << endl;
    }
    
    if (trafficDensity > 70 && weather >= 3)
    {
        cout << "Expect Heavy Delays" << endl;
    }
    else if (trafficDensity < 30 && weather == 1)
    {
        cout << "Expect Ideal Traffic" << endl;
    }
    else
    {
        cout << "Expect Moderate Traffic" << endl;
    }

    cout << "------------------------------------" << endl;
}

void displayCityMap()
{
    cout << endl << "------------------------------------" << endl;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int roadItem = rand() % 100;

            if (roadItem <= 9)
            {
                cout << "B ";        // Bus Stop
            }
            else if (roadItem <= 19)
            {
                cout << "M ";        // Metro
            }
            else if (roadItem <= 29)
            {
                cout << "T ";        // Traffic Light
            }
            else
            {
                cout << ". ";        // Road
            }
        }
        cout << endl;
    }
    cout << "------------------------------------" << endl;
}