#include <iostream>
using namespace std;

class Car {
private:
    string brand;

public:
    // Constructor
    Car(string b) : brand(b) {
        cout << "Car " << brand << " is created." << endl;
    }

    // Destructor
    ~Car() {
        cout << "Car " << brand << " is destroyed." << endl;
    }
};

int main() {
    Car car1("Tesla");  // Constructor is called

    // Destructor will be called automatically when the object goes out of scope
    return 0;
}

