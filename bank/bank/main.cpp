#include <iostream>
#include <limits>

using namespace std;

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
    cout << "Invalid input. Please enter a numeric pincode." << endl;
}
                 
int main() {
    int money = 10000;
    int pincode = 1234;
    int maxAttempts = 3;
    int userTry = 0;
    char unit = '$';
    
    int userPincode;
    int choice;
    int depositAmount;
    int withdrawAmount;
    
    while (userTry < maxAttempts) {
        
        cout << "Enter pincode: ";
        cin >> userPincode;
        
        if(cin.fail()) {
            handleInvalidInput();
            continue;
        }
        
        userTry++;
        
        if(userPincode == pincode) {
            cout << "Logged in successfull" << endl;
            
            while(true) {
                displayMenu();
                cin >> choice;
                
                if(cin.fail()) {
                    handleInvalidInput();
                    continue;
                }
                
                switch(choice) {
                    case 1:
                        cout << money << unit << endl;
                        break;
                    case 2:
                        cout << "Please enter amount you want to deposit: " << endl;
                        cin >> depositAmount;
                        
                        if(cin.fail()) {
                            handleInvalidInput();
                            continue;
                        } else if (!isValidAmount(depositAmount)) {
                            cout << "Invalid input. Please enter a valid amount." << endl;
                        } else {
                            money += depositAmount;
                            cout << "New balance: " << money << unit << endl;
                        }
                        break;
                    case 3:
                        cout << "Please enter the amount you want to withdraw: ";
                        cin >> withdrawAmount;
                        
                        if(cin.fail()) {
                            handleInvalidInput();
                            continue;
                        } else if (!isValidAmount(withdrawAmount)) {
                            cout << "Invalid input. Please enter a valid amount" << endl;
                        } else if (withdrawAmount > money) {
                            cout << "There is not enough money on your bank account" << endl;
                        } else {
                            money -= withdrawAmount;
                            cout << money << unit << endl;
                        }
                        break;
                    case 4:
                        cout << "Exiting... " << endl;
                        return 0;
                    default:
                        cout << "No such option. Please try again" << endl;
                }
            }
        } else {
            cout << "You entered wrong code. Attempts left: " << (maxAttempts - userTry) << endl;
        }
    }
    
    if (userTry >= maxAttempts) {
        cout << "You entered the wrong pincode 3 times. Your card has been blocked. Please call your bank." << endl;
    }
    
    return 0;
}
