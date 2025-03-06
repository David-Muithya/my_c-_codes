#include <iostream>
using namespace std;

class Pattern
{
private:
    int i, j;
    char ch;

public:
    void display()
    {
        // Outer loop for rows
        for (i = 1; i <= 5; i++)
        {
            ch = 'A'; // Reset the character to 'A' for each row
            // Inner loop for columns
            for (j = 1; j <= i; j++)
            {
                cout << ch << " \t"; // Print the character followed by a tab
                ch++; // Move to the next character
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
