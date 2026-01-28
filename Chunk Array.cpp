// Chunk Array.cpp

#include <iostream>
using namespace std;

void chunkArray(int arr[], int arrSize, int chunkSize);

int main()
{
    // Declare and Initialize Array, Declare Size of Array
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    const int length = 7;

    // Declare Chunk Size
    int chunkSize;
    cout << "Enter Chunk Size: ";
    cin >> chunkSize;

    // Chunk Array
    chunkArray(arr, length, chunkSize);

    return 0;
}

void chunkArray(int arr[], int arrSize, int chunkSize)
{
    int index = 0;

    cout << "[";

    // Outer Loop - Declares Groups
    for (int counter = 0; counter < (arrSize / chunkSize); counter++)
    {
        cout << "[";

        // Inner Loop - Inputs into Groups
        for (int i = 0; i < chunkSize && index < arrSize; i++)
        {
            cout << arr[index];
            index++;

            if (((i + 1) < chunkSize) && (index < arrSize))
            {
                cout << ",";
            }
        }
        
        cout << "]";
        if ((counter + 1) < (arrSize / chunkSize))
        {
            cout << ",";
        }
    }

    cout << "]";
}