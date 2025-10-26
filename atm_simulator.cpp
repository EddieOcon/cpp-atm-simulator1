#include <iostream>
using namespace std;

// Function prototypes
double checkBalance(double balance);
bool deposit(double &balance, double amount);
bool withdraw(double &balance, double amount);

int main() {
    double balance = 0.0;
    int choice = 0;

    do {
        cout << "Welcome to the ATM\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Menue input validation
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input. Please enter a number from 1 to 4.\n\n";
            continue;
        }

        if (choice == 1) {
            double current = checkBalance(balance); // pass-by-value
            cout << "Current Balance: $" << current << "\n\n";
        } else if (choice == 2) {
            double amount = 0.0;
            cout << "Enter the amount you want to deposit: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid amount.\n\n";
                continue;
            }

            if (deposit(balance, amount)) {
                cout << "Deposit successful.\n";
            } else {
                cout << "Deposit failed. Amount must be positive.\n";
            }
            cout << "\n";
        } else if (choice == 3) {
            double amount = 0.0;
            cout << "Enter amount to withdraw: ";
            cin >> amount;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid amount.\n\n";
                continue;
            }

            if (withdraw(balance, amount)) {
                cout << "Withdrawal successful.\n";
            } else {
                cout << "Withdrawal failed. Amount must be positive and with in the balance.\n";
            }
            cout << "\n";
        } else if (choice == 4) {
            cout << "Thank you for using the ATM. Goodbye.\n";
        } else {
            cout << "Please enter a valid option (1-4).\n\n";
        }
    } while (choice != 4);

    return 0;
}

// Returns the current balance (pass-by-value demonstration)
double checkBalance(double balance) {
    return balance;
}

// Deposits amount into balance (pass-by-reference). Returns true if successful.
bool deposit(double &balance, double amount) {
    if (amount < 0.0) {
        return false; // prevent negative deposit
    }
    balance += amount;
    return true;
}

// Withdraws amount from balance (pass-by-reference). Returns true if successful.
bool withdraw(double &balance, double amount) {
    if (amount < 0.0) {
        return false; // prevent negative withdrawal
    }
    if (amount > balance) {
        return false; // prevent overdraft
    }
    balance -= amount;
    return true;
}
