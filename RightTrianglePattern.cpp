#include <iostream>
using namespace std;

class Pattern
{
private:
    int i, j;

public:
    void display()
    {
        // Outer loop for rows
        for (i = 1; i <= 5; i++)
        {
            // Inner loop for columns
            for (j = 1; j <= i; j++)
            {
                cout << "* \t"; // Print "*" followed by a tab
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
