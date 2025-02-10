#include <iostream>
using namespace std;

int main() {
    int num1 = 10;
    int num2 = 5;

    // Basic arithmetic operations
    int sum = num1 + num2;
    int difference = num1 - num2;
    int product = num1 * num2;
    float quotient = (float) num1 / num2;  // Type casting to float for division

    // Print the results
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << difference << endl;
    cout << "Product: " << product << endl;
    cout << "Quotient: " << quotient << endl;

    return 0;
}

