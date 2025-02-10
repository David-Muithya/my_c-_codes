#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
using namespace std;

// Base class for Student
class Student {
protected:
    string name;
    int age;
    double grade;

public:
    Student(string n, int a, double g) : name(n), age(a), grade(g) {}

    virtual void display() const {
        cout << "Name: " << name << ", Age: " << age << ", Grade: " << grade << endl;
    }

    string getName() const {
        return name;
    }

    double getGrade() const {
        return grade;
    }

    virtual void saveToFile(ofstream &outFile) const {
        outFile << name << "," << age << "," << grade << endl;
    }
};

// Derived class for HonorsStudent
class HonorsStudent : public Student {
private:
    double honorsGrade;

public:
    HonorsStudent(string n, int a, double g, double h) : Student(n, a, g), honorsGrade(h) {}

    void display() const override {
        cout << "Honors " << "Name: " << name << ", Age: " << age << ", Grade: " << grade << ", Honors Grade: " << honorsGrade << endl;
    }

    void saveToFile(ofstream &outFile) const override {
        outFile << name << "," << age << "," << grade << "," << honorsGrade << endl;
    }
};

// Class for managing students
class StudentManagementSystem {
private:
    Student **students;
    int size;
    const string fileName = "students.txt";

public:
    StudentManagementSystem() : students(nullptr), size(0) {}

    void addStudent(Student *newStudent) {
        Student **newStudents = new Student*[size + 1];
        for (int i = 0; i < size; i++) {
            newStudents[i] = students[i];
        }
        newStudents[size] = newStudent;

        delete[] students;
        students = newStudents;
        size++;
    }

    void displayAllStudents() const {
        if (size == 0) {
            cout << "No students available!" << endl;
            return;
        }
        cout << "\nDisplaying All Students: \n";
        for (int i = 0; i < size; i++) {
            students[i]->display();
        }
    }

    void deleteStudent(string studentName) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (students[i]->getName() == studentName) {
                delete students[i];
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                found = true;
                cout << "Student " << studentName << " deleted successfully!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student not found!" << endl;
        }
    }

    void saveToFile() const {
        ofstream outFile(fileName);
        if (!outFile) {
            throw runtime_error("Error opening file for saving data.");
        }
        for (int i = 0; i < size; i++) {
            students[i]->saveToFile(outFile);
        }
        outFile.close();
        cout << "Data saved to file successfully!" << endl;
    }

    void loadFromFile() {
        ifstream inFile(fileName);
        if (!inFile) {
            throw runtime_error("Error opening file for loading data.");
        }

        string name;
        int age;
        double grade, honorsGrade;
        while (getline(inFile, name, ',') && inFile >> age && inFile.ignore(1, ',') && inFile >> grade) {
            inFile.ignore(1, ',');
            if (inFile.peek() != '\n') { // If there is honors grade
                inFile >> honorsGrade;
                inFile.ignore(1, '\n');
                addStudent(new HonorsStudent(name, age, grade, honorsGrade));
            } else {
                inFile.ignore(1, '\n');
                addStudent(new Student(name, age, grade));
            }
        }
        inFile.close();
        cout << "Data loaded from file successfully!" << endl;
    }

    ~StudentManagementSystem() {
        for (int i = 0; i < size; i++) {
            delete students[i];
        }
        delete[] students;
    }
};

int main() {
    try {
        StudentManagementSystem sms;

        sms.loadFromFile();  // Load students from file if exists

        sms.addStudent(new Student("Alice", 20, 85.5));
        sms.addStudent(new HonorsStudent("Bob", 22, 91.0, 95.0));
        sms.addStudent(new Student("Charlie", 21, 75.3));

        sms.displayAllStudents();

        sms.deleteStudent("Alice");

        sms.displayAllStudents();

        sms.saveToFile(); // Save updated data to file
    } catch (const exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

