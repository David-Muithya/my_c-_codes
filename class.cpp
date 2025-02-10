#include <iostream>
using namespace std;

// Define a class representing a Car
class Car {
private:
    string brand;
    string model;
    int year;

public:
    // Constructor
    Car(string b, string m, int y) : brand(b), model(m), year(y) {}

    // Method to display car details
    void displayDetails() {
        cout << "Car Brand: " << brand << endl;
        cout << "Car Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Creating an object of Car class
    Car car1("Tesla", "Model S", 2023);

    // Calling the method to display details
    car1.displayDetails();

    return 0;
}

