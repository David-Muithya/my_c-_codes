#include <iostream>
using namespace std;

int main() {
    // Declare and initialize an array of integers
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);  // Get the size of the array

    // Loop through the array and print each number
    for (int i = 0; i < size; i++) {
        cout << "Element " << i + 1 << ": " << numbers[i] << endl;
    }

    return 0;
}

