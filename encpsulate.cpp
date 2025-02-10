#include <iostream>
using namespace std;

class Account {
private:
    double balance;

public:
    // Constructor to initialize balance
    Account(double initial_balance) : balance(initial_balance) {}

    // Getter for balance
    double getBalance() {
        return balance;
    }

    // Setter to deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Setter to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds or invalid amount." << endl;
        }
    }
};

int main() {
    // Create an Account object
    Account acc(1000.0);  // Initial balance of 1000

    cout << "Initial Balance: $" << acc.getBalance() << endl;

    // Deposit and withdraw money
    acc.deposit(500);
    cout << "Balance after deposit: $" << acc.getBalance() << endl;

    acc.withdraw(200);
    cout << "Balance after withdrawal: $" << acc.getBalance() << endl;

    return 0;
}

