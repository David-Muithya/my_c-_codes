#include <iostream>
#include <string>
using namespace std;

// Student class to store information
class Student {
private:
    string name;
    int age;
    double grade;

public:
    Student(string n, int a, double g) : name(n), age(a), grade(g) {}

    void displayInfo() {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }

    // Accessors
    string getName() {
        return name;
    }

    double getGrade() {
        return grade;
    }
};

// Class to manage student records
class StudentManagementSystem {
private:
    Student** students;
    int size;

public:
    StudentManagementSystem() : students(nullptr), size(0) {}

    void addStudent(string name, int age, double grade) {
        // Dynamically allocate memory for a new student array
        Student** newStudents = new Student*[size + 1];

        // Copy old student data
        for (int i = 0; i < size; i++) {
            newStudents[i] = students[i];
        }

        // Add new student
        newStudents[size] = new Student(name, age, grade);

        // Delete old array and point to new one
        delete[] students;
        students = newStudents;
        size++;
    }

    void displayAllStudents() {
        cout << "\nAll Students:\n";
        for (int i = 0; i < size; i++) {
            students[i]->displayInfo();
        }
    }

    void deleteStudent(string name) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (students[i]->getName() == name) {
                found = true;
                delete students[i];

                // Shift the array
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;

                cout << "Student " << name << " removed from the system." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student " << name << " not found!" << endl;
        }
    }

    ~StudentManagementSystem() {
        for (int i = 0; i < size; i++) {
            delete students[i];
        }
        delete[] students;
    }
};

int main() {
    StudentManagementSystem sms;

    sms.addStudent("Alice", 20, 88.5);
    sms.addStudent("Bob", 22, 91.2);
    sms.addStudent("Charlie", 21, 75.3);

    sms.displayAllStudents();

    sms.deleteStudent("Bob");

    sms.displayAllStudents();

    return 0;
}

