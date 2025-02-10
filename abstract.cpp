#include <iostream>
using namespace std;

class Shape {
public:
    // Pure virtual function makes this class abstract
    virtual void draw() = 0;  // Pure virtual function
    virtual double area() = 0; // Pure virtual function
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    void draw() override {
        cout << "Drawing a circle" << endl;
    }

    double area() override {
        return 3.14 * radius * radius;  // Area of the circle
    }
};

int main() {
    Circle c(5);  // Create a circle with radius 5
    c.draw();     // Outputs: Drawing a circle
    cout << "Area of the circle: " << c.area() << endl;

    return 0;
}

