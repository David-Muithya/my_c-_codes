#include <iostream>
using namespace std;

class pattern
{
private:
    int i;
    int j;

public:
    void display()
    {
        // Outer loop for rows
        for (i = 1; i <= 3; i++)
        {
            // Inner loop for columns
            for (j = 1; j <= 4; j++)
            {
                cout << "c \t"; // Print "c" followed by a tab
            }
            cout << "\n"; // Move to the next line after each row
        }
    }
};

int main()
{
    pattern p;
    p.display(); // Call the display function to print the pattern
    return 0;
}
