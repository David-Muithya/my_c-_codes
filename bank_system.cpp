#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    double balance;
public:
    // Constructor initializes balance
    BankAccount(double initialBalance) : balance(initialBalance) {}

    // Deposit money into the account
    void deposit(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive.");
        }
        balance += amount;
        cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive.");
        }
        if (amount > balance) {
            throw runtime_error("Insufficient funds.");
        }
        balance -= amount;
        cout << "Withdrew: $" << amount << ". New balance: $" << balance << endl;
    }

    // Display balance
    void displayBalance() {
        cout << "Current balance: $" << balance << endl;
    }
};

int main() {
    try {
        BankAccount account(1000.0);

        account.displayBalance();

        account.deposit(500.0);
        account.withdraw(200.0);
        account.withdraw(1500.0); // This will cause an error

        account.displayBalance();
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

