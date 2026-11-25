
// ACTIVITY 4: BANK ACCOUNT CLASS
// Learning Outcome: Create a class with methods and validation

#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    double balance;

public:
    // Constructor: Sets up the account with an initial balance
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        // Only allow a positive initial balance
        if (initialBalance >= 0) {
            balance = initialBalance;
        } else {
            balance = 0;
            cout << "Warning: Initial balance cannot be negative. Setting balance to 0." << endl;
            
        }
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        // VALIDATION: Only allow positive deposits
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited: $" << amount << endl;
        } else {
            cout << "Error: Deposit amount must be greater than zero." << endl;
        }
    }   

    // Method to withdraw money from the account
    void withdraw(double amount) {
        // VALIDATION: Only allow withdrawals if there are sufficient funds
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Successfully withdrew: $" << amount << endl;
        } else if (amount > balance) {
            cout << "Error: Insufficient funds for withdrawal." << endl;
        } else {
            cout << "Error: Withdrawal amount must be greater than zero." << endl;
        }
    }

    // Method to check the current balance
    void displayBalance() {
        cout << "Account Holder:" << accountHolder << endl;
        cout << "Current Balance: $" << balance << endl;
    }      
};

int main() {
    cout << "--- Opening Account ---" << endl;  
    // Create an account for Alice with $500
    BankAccount aliceAccount("Alice Smith", 500.00);
    aliceAccount.displayBalance();

    cout << "\n--- Attempting Deposits ---" << endl;
    aliceAccount.deposit(200.00); // Valid deposit
    aliceAccount.deposit(-50.00); // Invalid deposit

    cout << "\n--- Attempting Withdrawals ---" << endl;
    aliceAccount.withdraw(100.00); // Valid withdrawal
    aliceAccount.withdraw(1000.00); // Invalid withdrawal (insufficient funds)
    aliceAccount.withdraw(-20.00); // Invalid withdrawal (negative amount)

    cout << "\n--- Final Account Status ---" << endl;
    aliceAccount.displayBalance();

    return 0;
}