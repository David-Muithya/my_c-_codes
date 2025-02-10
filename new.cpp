#include <iostream>
using namespace std;

int main() {
    // Dynamically allocating memory for an integer
    int* ptr = new int;

    // Assigning a value to the allocated memory
    *ptr = 50;
    cout << "Value stored in dynamically allocated memory: " << *ptr << endl;

    // Dynamically allocating memory for an array of integers
    int size = 5;
    int* arr = new int[size];  // Allocating an array of 5 integers

    // Assign values to the array
    for (int i = 0; i < size; i++) {
        arr[i] = i * 10;
    }

    // Print the array values
    cout << "Array values: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Deallocating memory using delete
    delete ptr;   // Deallocate single integer memory
    delete[] arr; // Deallocate array memory

    return 0;
}

