#include <iostream>
#include <stdexcept>  // For standard exceptions
using namespace std;

int divide(int a, int b) {
    if (b == 0) {
        throw runtime_error("Division by zero is not allowed");
    }
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);  // This will throw an exception
        cout << "Result: " << result << endl;
    }
    catch (const runtime_error& e) {  // Catch the exception
        cout << "Error: " << e.what() << endl;  // Print the error message
    }

    return 0;
}

