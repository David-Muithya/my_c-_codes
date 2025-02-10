#include <iostream>
using namespace std;

// Function to calculate the area of a rectangle
float calculateArea(float length, float width) {
    return length * width;  // Formula for area: length * width
}

int main() {
    float length = 10.5;
    float width = 4.2;

    // Calling the function and storing the result
    float area = calculateArea(length, width);

    // Displaying the result
    cout << "The area of the rectangle is: " << area << " square units." << endl;

    return 0;
}

