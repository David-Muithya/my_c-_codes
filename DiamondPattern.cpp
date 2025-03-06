#include <iostream>
using namespace std;

class Pattern
{
private:
    int i, j, space;

public:
    void display()
    {
        // Upper half of the diamond
        for (i = 1; i <= 5; i++)
        {
            // Printing spaces
            for (space = 1; space <= 5 - i; space++)
            {
                cout << " \t";
            }
            // Printing stars
            for (j = 1; j <= (2 * i - 1); j++)
            {
                cout << "* \t";
            }
            cout << "\n"; // Move to the next line
        }

        // Lower half of the diamond
        for (i = 4; i >= 1; i--)
        {
            // Printing spaces
            for (space = 1; space <= 5 - i; space++)
            {
                cout << " \t";
            }
            // Printing stars
            for (j = 1; j <= (2 * i - 1); j++)
            {
                cout << "* \t";
            }
            cout << "\n"; // Move to the next line
        }
    }
};

int main()
{
    Pattern p;
    p.display(); // Call the display function to print the pattern
    return 0;
}
