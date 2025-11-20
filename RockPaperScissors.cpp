// RockPaperScissors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    srand(time(0));

    // Step 1 - User's Choice

    string user;
    cin >> user;

    // Step 2 - Computer's Choice

    int r = rand() % 3;
    string comp;

    if (r == 0) comp = "rock";
    if (r == 1) comp = "paper";
    if (r == 2) comp = "scissors";

    // Step 3 - Print Both Choices

    cout << "\nThe user chose " << user << endl;
    cout << "The computer chose " << comp << endl;

    // Step 4 - Determine Results

    if (user == "rock")
    {
        if (comp == "rock") cout << "Tie!";
        if (comp == "paper") cout << "Computer Wins!";
        if (comp == "scissors") cout << "User Wins!";
    }
    else if (user == "paper")
    {
        if (comp == "rock") cout << "User Wins!";
        if (comp == "paper") cout << "Tie!";
        if (comp == "scissors") cout << "Computer Wins";
    }
    else if (user == "scissors")
    {
        if (comp == "rock") cout << "Computer Wins!";
        if (comp == "paper") cout << "User Wins!";
        if (comp == "scissors") cout << "Tie!";
    }
    else
    {
        cout << "Invalid Test. User Input Error";
    }

    cout << "\n";
    return 0;
}