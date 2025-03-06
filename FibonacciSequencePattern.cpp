#include <iostream>
using namespace std;

class Pattern
{
private:
    int i, j;
    int a, b, next;

public:
    void display()
    {
        a = 0;
        b = 1;
        // Outer loop for rows
        for (i = 1; i <= 5; i++)
        {
            // Inner loop for columns
            for (j = 1; j <= i; j++)
            {
                cout << a << " \t"; // Print the Fibonacci number followed by a tab
                next = a + b;
                a = b;
                b = next;
            }
            cout << "\n"; // Move to the next line after each row
        }
    }
};

int main()
{
    Pattern p;
    p.display(); // Call the display function to print the pattern
    return 0;
}
