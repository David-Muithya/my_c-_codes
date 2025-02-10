#include <iostream>
using namespace std;

// Define the Rectangle class
class Rectangle {
private:
    float length, width;  // Private member variables

public:
    // Constructor to initialize the rectangle
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }

    // Method to calculate the area
    float calculateArea() {
        return length * width;
    }

    // Method to display the dimensions
    void displayDimensions() {
        cout << "Length: " << length << ", Width: " << width << endl;
    }
};

int main() {
    // Create an object of Rectangle
    Rectangle rect(10.5, 4.2);

    // Display the rectangle's dimensions and area
    rect.displayDimensions();
    cout << "Area: " << rect.calculateArea() << " square units." << endl;

    return 0;
}

