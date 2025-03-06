#include <iostream>
using namespace std;

int main() {
    int marks[4];
    string grade, remark;

    // Input marks for 4 subjects
    cout << "Enter marks for 4 subjects (0-100):\n";
    for (int i = 0; i < 4; i++) {
        cout << "Subject " << i + 1 << ": ";
        cin >> marks[i];

        // Check if the marks are within the valid range (0-100)
        if (marks[i] < 0 || marks[i] > 100) {
            cout << "Invalid marks entered! Please enter a value between 0 and 100.\n";
            return 1; // Exit the program if invalid input is detected
        }
    }

    // Process the marks using switch case
    for (int i = 0; i < 4; i++) {
        switch (marks[i] / 10) {
            case 10:
            case 9:  // 90-100
                grade = "A";
                remark = "EXCELLENT";
                break;
            case 8:  // 80-89
                grade = "A";
                remark = "EXCELLENT";
                break;
            case 7:  // 70-79
                grade = "B";
                remark = "GOOD";
                break;
            case 6:  // 60-69
                grade = "C";
                remark = "SATISFACTORY";
                break;
            case 5:  // 50-59
                grade = "D";
                remark = "PASS";
                break;
            case 4:  // 40-49
                grade = "D";
                remark = "PASS";
                break;
            default:  // 0-39
                grade = "F";
                remark = "FAIL";
                break;
        }
        // Display result for each subject
        cout << "\n Subject " << i + 1 << " - Marks: " << marks[i] << ", Grade: " << grade << ", Remark: " << remark << endl;
    }

    return 0;
}
