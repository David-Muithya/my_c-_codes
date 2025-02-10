#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    double grade;

public:
    Student(string n, double g) : name(n), grade(g) {}

    void display() {
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }

    string getName() {
        return name;
    }

    double getGrade() {
        return grade;
    }

    void saveToFile(ofstream& outFile) {
        outFile << name << "," << grade << endl;
    }
};

int main() {
    // Writing to file
    ofstream outFile("grades.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return 1;
    }

    Student s1("Alice", 95.5);
    Student s2("Bob", 88.0);
    Student s3("Charlie", 72.3);

    s1.saveToFile(outFile);
    s2.saveToFile(outFile);
    s3.saveToFile(outFile);

    outFile.close(); // Close file after writing

    // Reading from file
    ifstream inFile("grades.txt");
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return 1;
    }

    string line;
    while (getline(inFile, line)) {
        size_t commaPos = line.find(',');
        string name = line.substr(0, commaPos);
        double grade = stod(line.substr(commaPos + 1));

        Student temp(name, grade);
        temp.display();
    }

    inFile.close(); // Close file after reading

    return 0;
}

