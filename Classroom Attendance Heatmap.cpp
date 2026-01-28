// Classroom Attendance Heatmap.cpp

#include <iostream>
using namespace std;

int main()
{
    const int numStudents = 3;
    const int numDays = 4;

    int attendance[numStudents][numDays];

    // Input Values
    cout << "0 = Absent \t1 = Present" << endl;
    for (int row = 0; row < numStudents; row++)
    {
        for (int col = 0; col < numDays; col++)
        {
            cout << "Student " << row + 1 << " on Day " << col + 1 << ": ";
            cin >> attendance[row][col];

            if (attendance[row][col] != 1 && attendance[row][col] != 0)
            {
                cout << "\nInvalid Input" << endl;
                return 0;
            }
        }
        cout << endl;
    }
    
    // Display Heatmap
    cout << "\t\tDay 1 \tDay 2 \tDay 3 \tDay 4" << endl;
    for (int row = 0; row < numStudents; row++)
    {
        cout << "Student 1";
        for (int col = 0; col < numDays; col++)
        {
            cout << "\t" << attendance[row][col];
        }
        cout << endl;
    }
    cout << endl;

    // Data (per Student)
    for (int row = 0; row < numStudents; row++)
    {
        int absenceTotal = 0;
        int presenceTotal = 0;
        for (int col = 0; col < numDays; col++)
        {
            if (attendance[row][col] == 0)
            {
                absenceTotal++;
            }
            else
            {
                presenceTotal++;
            }
        }
        cout << "Student " << row + 1 << ": Present = " << presenceTotal << ", Absent = " << absenceTotal << endl;
        
        if (absenceTotal >= 2)
        {
            cout << "Warning: Student " << row + 1 << " has " << absenceTotal << " absences!" << endl;
        }

        cout << endl;
    }

    // Data (Worst Day)
    int worstDay = 0;
    int maxAbsences = 0;

    for (int col = 0; col < numDays; col++)
    {
        int tempAbsences = 0;
        for (int row = 0; row < numStudents; row++)
        {
            if (attendance[row][col] == 0)
            {
                tempAbsences++;
            }
        }
        if (tempAbsences > maxAbsences)
        {
            maxAbsences = tempAbsences;
            worstDay = col + 1;
        }
    }

    cout << "Worst Attendance Day: Day " << worstDay << " (" << maxAbsences << " Absences)" << endl;

    
    return 0;
}