// Daily Electricity Usage Analyzer.cpp
// Samuel Holmes    1/21/2026

#include <iostream>
using namespace std;

// Function Declarations
void input_usage(int arr[], int size);
int  choice_Menu();
void display_daily_usage(int arr[], int size);
void total_weekly_usage(int arr[], int size);
void average_daily_usage(int arr[], int size);
void find_highest_usage(int arr[], int size);
void days_above_10(int arr[], int size);


int main()
{
	const int numDays = 7;
	int usage[numDays];

	// Step 1 - Input Usage
	input_usage(usage, numDays);

	// Step 2 - Repeating Menu
	int choice = 0;
	do
	{
		choice = choice_Menu();
		cout << endl;
		switch (choice)
		{
			case 1:
			{
				display_daily_usage(usage, numDays);
				break;
			}
			case 2:
			{
				total_weekly_usage(usage, numDays);
				break;
			}
			case 3:
			{
				average_daily_usage(usage, numDays);
				break;
			}
			case 4:
			{
				find_highest_usage(usage, numDays);
				break;
			}
			case 5:
			{
				days_above_10(usage, numDays);
				break;
			}
			case 6:
			{
				break;
			}
			default:
			{
				cout << "Invalid Input" << endl;
				return 0;
			}
		}

	} while (choice != 6);

	return 0;
}

// Function Definitions
void input_usage(int arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << "Enter Usage for Day " << index + 1 << ": ";
		cin >> arr[index];
	}
}

int choice_Menu()
{
	cout << "\n===== ===== MENU ===== =====" << endl;
	cout << "1. Display Daily Usage" << endl;
	cout << "2. Total Weekly Usage" << endl;
	cout << "3. Average Daily Usage" << endl;
	cout << "4. Highest Usage Value" << endl;
	cout << "5. Count Days Above 10 Units" << endl;
	cout << "6. Exit" << endl;

	int choice;
	cout << "\nEnter Choice: ";
	cin >> choice;
	return choice;
}

void display_daily_usage(int arr[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << "Day " << index + 1 << ": " << arr[index] << endl;
	}
}

void total_weekly_usage(int arr[], int size)
{
	int total = 0;
	for (int index = 0; index < size; index++)
	{
		total += arr[index];
	}

	cout << "Total Usage: " << total << endl;
}

void average_daily_usage(int arr[], int size)
{
	int total = 0;
	for (int index = 0; index < size; index++)
	{
		total += arr[index];
	}

	cout << "Average Usage: " << (total / (double)size) << endl;
}

void find_highest_usage(int arr[], int size)
{
	int highest = 0;
	for (int index = 0; index < size; index++)
	{
		if (arr[index] > highest)
		{
			highest = arr[index];
		}
	}

	cout << "Highest Usage: " << highest << endl;
}

void days_above_10(int arr[], int size)
{
	int numDays = 0;
	for (int index = 0; index < size; index++)
	{
		if (arr[index] > 10)
		{
			numDays++;
		}
	}

	cout << "Number of Days above 10 Units: " << numDays << endl;
}