#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

using namespace std;

// Define the Account struct
struct Account {
    int pin;
    int amount;
    string accountHolderName;
};

// Create an array of accounts
Account accounts[] = {
    { 1234, 10000, "Joe Smith" },
    { 4321, 5000, "Jake Doe" }
};

const int numAccounts = sizeof(accounts) / sizeof(accounts[0]);  // Number of accounts

void displayMenu() {
    cout << "1. Display account balance" << endl;
    cout << "2. Deposit" << endl;
    cout << "3. Withdraw" << endl;
    cout << "4. Exit" << endl;
}

bool isValidAmount(int amount) {
    return amount > 0;
}

void handleInvalidInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input. Please enter a numeric value." << endl;
}

int main() {
    int maxAttempts = 3;
    int userTry = 0;
    char unit = '$';

    int userPincode;
    int choice;
    int depositAmount;
    int withdrawAmount;
    int selectedAccountIndex = -1;  // To store the index of the logged-in account

    while (userTry < maxAttempts) {

        cout << "Enter pincode: ";
        cin >> userPincode;

        if (cin.fail()) {
            handleInvalidInput();
            continue;
        }

        userTry++;

        // Check if the entered PIN matches any account's PIN
        for (int i = 0; i < numAccounts; i++) {
            if (userPincode == accounts[i].pin) {
                selectedAccountIndex = i;  // Store the index of the correct account
                cout << "Logged in successfully as " << accounts[i].accountHolderName << endl;

                // Enter the ATM menu
                while (true) {
                    displayMenu();
                    cin >> choice;

                    if (cin.fail()) {
                        handleInvalidInput();
                        continue;
                    }

                    switch (choice) {
                        case 1:
                            cout << "Balance: " << accounts[selectedAccountIndex].amount << unit << endl;
                            break;
                        case 2:
                            cout << "Please enter amount you want to deposit: " << endl;
                            cin >> depositAmount;

                            if (cin.fail()) {
                                handleInvalidInput();
                                continue;
                            } else if (!isValidAmount(depositAmount)) {
                                cout << "Invalid input. Please enter a valid amount." << endl;
                            } else {
                                accounts[selectedAccountIndex].amount += depositAmount;
                                cout << "New balance: " << accounts[selectedAccountIndex].amount << unit << endl;
                            }
                            break;
                        case 3:
                            cout << "Please enter the amount you want to withdraw: ";
                            cin >> withdrawAmount;

                            if (cin.fail()) {
                                handleInvalidInput();
                                continue;
                            } else if (!isValidAmount(withdrawAmount)) {
                                cout << "Invalid input. Please enter a valid amount" << endl;
                            } else if (withdrawAmount > accounts[selectedAccountIndex].amount) {
                                cout << "There is not enough money on your bank account" << endl;
                            } else {
                                accounts[selectedAccountIndex].amount -= withdrawAmount;
                                cout << "New balance: " << accounts[selectedAccountIndex].amount << unit << endl;
                            }
                            break;
                        case 4:
                            cout << "Exiting... " << endl;
                            return 0;
                        default:
                            cout << "No such option. Please try again." << endl;
                    }
                }
            }
        }

        if (selectedAccountIndex == -1) {
            cout << "Incorrect PIN. Attempts left: " << (maxAttempts - userTry) << endl;
        }

        if (userTry >= maxAttempts) {
            cout << "You entered the wrong PIN 3 times. Please wait 30 seconds before trying again." << endl;
            this_thread::sleep_for(chrono::seconds(30));
            userTry = 0;
        }
    }

    return 0;
}