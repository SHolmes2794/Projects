// Supermarket Weekly Sales Analyzer.cpp

#include <iostream>
using namespace std;

const int cashiers = 3;
const int days = 4;

void input_sales(int arr[][days], int cashiers);
void analyze_sales(int arr[][days], int cashiers);
void best_cashier(int arr[][days], int cashiers);

int main()
{
    int sales[cashiers][days];

    input_sales(sales, cashiers);
    analyze_sales(sales, cashiers);
    best_cashier(sales, cashiers);


    return 0;
}

void input_sales(int arr[][days], int cashiers)
{
    for (int row = 0; row < cashiers; row++)
    {
        for (int col = 0; col < days; col++)
        {
            cout << "Enter cashier " << row + 1 << " sales on day " << col + 1 << ": ";
            cin >> arr[row][col];
        }
    }
}

void analyze_sales(int arr[][days], int cashiers)
{
    // For Each Cashier
    for (int row = 0; row < cashiers; row++)
    {
        int total = 0;
        int max_sale = arr[row][0];
        int best_day = 0;

        for (int col = 0; col < days; col++)
        {
            // Calculate and Print Total Sales
            total += arr[row][col];

            // Find and Print Best Day / Highest Sale
            if (arr[row][col] > max_sale)
            {
                max_sale = arr[row][col];
                best_day = col + 1;
            }
        }

        cout << "\nCashier " << row + 1 << " Total Sales: $" << total << endl;
        cout << "Cashier " << row + 1 << " Best Day: Day " << best_day << " (" << max_sale << ")" << endl;
    }
}

void best_cashier(int arr[][days], int cashiers)
{
    // Find Cashier with Best Total Sales
    int best_cashier = 0;
    int highest_total = 0;
    for (int row = 0; row < cashiers; row++)
    {
        int temp_max = 0;

        for (int col = 0; col < days; col++)
        {
            temp_max += arr[row][col];
        }

        if (temp_max > highest_total)
        {
            best_cashier = row + 1;
            highest_total = temp_max;
        }
    }

    cout << "\nBest Cashier: Cashier " << best_cashier << " (Total of $" << highest_total << ")" << endl;
}