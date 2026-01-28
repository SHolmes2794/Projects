// Rotate an Array to the Right by K Steps.cpp

#include <iostream>
using namespace std;

void rotateArray(int arr[], int size, int rotations);
void printArray(int arr[], int size);

int main()
{
    // Declare and Initialize Array, Declare Size of Array
    int numbers[] = { 1, 2, 3, 4, 5, 6, 7 };
    const int size = 7;

    // Print Original Array
    printArray(numbers, size);
    
    // Declare Number of Right Rotations
    int numRotations;
    cout << "\nEnter Number of Right Rotations: ";
    cin >> numRotations;

    // Rotate Array
    rotateArray(numbers, size, numRotations);

    // Print Rotated Array
    printArray(numbers, size);

    return 0;
}

void rotateArray(int arr[], int size, int rotations)
{
    
    for (int counter = 0; counter < rotations; counter++)
    {
        int lastItem = arr[size - 1];
        for (int index = size - 1; index > 0; index--)
        {
            arr[index] = arr[index - 1];
        }
        arr[0] = lastItem;
    }

    cout << endl;
}

void printArray(int arr[], int size)
{
    for (int index = 0; index < size; index++)
    {
        cout << arr[index] << " ";
    }
    cout << endl;
}