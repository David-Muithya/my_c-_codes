#include <iostream>
using namespace std;

// Base class (Parent class)
class Animal {
protected:
    string name;

public:
    // Constructor to initialize the name of the animal
    Animal(string n) : name(n) {}

    // Virtual function to make sound
    virtual void makeSound() {
        cout << name << " makes a sound" << endl;
    }
};

// Derived class (Child class)
class Dog : public Animal {
public:
    // Constructor to initialize name of the dog
    Dog(string n) : Animal(n) {}

    // Overriding makeSound() function
    void makeSound() override {
        cout << name << " barks" << endl;
    }
};

// Derived class (Child class)
class Cat : public Animal {
public:
    // Constructor to initialize name of the cat
    Cat(string n) : Animal(n) {}

    // Overriding makeSound() function
    void makeSound() override {
        cout << name << " meows" << endl;
    }
};

int main() {
    // Creating objects of derived classes
    Animal* animal1 = new Dog("Buddy");
    Animal* animal2 = new Cat("Whiskers");

    animal1->makeSound();  // Outputs: Buddy barks
    animal2->makeSound();  // Outputs: Whiskers meows

    // Clean up dynamically allocated memory
    delete animal1;
    delete animal2;

    return 0;
}

