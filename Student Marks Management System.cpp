// Student Marks Management System.cpp
// Samuel Holmes	1/21/2026

#include <iostream>
using namespace std;

// Function Declarations
void input_marks(int marks[], int size);
int teacherChoice_Menu();
void display_all_marks(int marks[], int size);
void find_total_marks(int marks[], int size);
void find_average_marks(int marks[], int size);
void count_passed_students(int marks[], int size);
void find_highest_mark(int marks[], int size);

// Main
int main()
{
	const int numStudents = 5;
	int marks[numStudents];

	// Step 1 - Input Marks
	input_marks(marks, numStudents);

	// Step 2 - Repeating Menu
	int choice = 0;
	do
	{
		choice = teacherChoice_Menu();
		cout << endl;
		switch (choice)
		{
			case 1:
			{
				display_all_marks(marks, numStudents);
				break;
			}
			case 2:
			{
				find_total_marks(marks, numStudents);
				break;
			}
			case 3:
			{
				find_average_marks(marks, numStudents);
				break;
			}
			case 4:
			{
				count_passed_students(marks, numStudents);
				break;
			}
			case 5:
			{
				find_highest_mark(marks, numStudents);
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
void input_marks(int marks[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << "Enter Marks for Student " << index + 1 << ": ";
		cin >> marks[index];
	}
}

int teacherChoice_Menu()
{
	cout << "\n===== ===== MENU ===== =====" << endl;
	cout << "1. Display All Marks" << endl;
	cout << "2. Find Total Marks" << endl;
	cout << "3. Find Average Marks" << endl;
	cout << "4. Count Passed Students" << endl;
	cout << "5. Find Highest Mark" << endl;
	cout << "6. Exit" << endl;

	int choice;
	cout << "\nEnter Choice: ";
	cin >> choice;
	return choice;
}

void display_all_marks(int marks[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << "Student " << index + 1 << ": " << marks[index] << endl;
	}
}

void find_total_marks(int marks[], int size)
{
	int total = 0;
	for (int index = 0; index < size; index++)
	{
		total += marks[index];
	}

	cout << "Total Marks: " << total << endl;
}

void find_average_marks(int marks[], int size)
{
	int total = 0;
	for (int index = 0; index < size; index++)
	{
		total += marks[index];
	}

	cout << "Average Marks: " << (total / (double) size) << endl;
}

void count_passed_students(int marks[], int size)
{
	int passCount = 0;
	for (int index = 0; index < size; index++)
	{
		if (marks[index] >= 40)
		{
			passCount++;
		}
	}

	cout << "Number of Passed Students: " << passCount << endl;
}

void find_highest_mark(int marks[], int size)
{
	int highest = 0;
	for (int index = 0; index < size; index++)
	{
		if (marks[index] > highest)
		{
			highest = marks[index];
		}
	}

	cout << "Highest Mark: " << highest << endl;
}