#include <iostream>
using namespace std;

class Shape {
public:
    virtual void draw() {
        cout << "Drawing a shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing a circle" << endl;
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing a rectangle" << endl;
    }
};

int main() {
    // Using base class pointer to call derived class methods
    Shape* shape1 = new Circle();
    Shape* shape2 = new Rectangle();

    shape1->draw();  // Outputs: Drawing a circle
    shape2->draw();  // Outputs: Drawing a rectangle

    // Clean up dynamically allocated memory
    delete shape1;
    delete shape2;

    return 0;
}

