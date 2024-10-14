#include <iostream>

using namespace std;

static char getOperator(string prompt) {
	char operation;
	while (true) {
		cout << prompt;
		cin >> operation;

		if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
			return operation;
		}
		else {
			cout << "Invalid operator. Please enter again. " << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

static double calculate(double firstNumber, double secondNumber, char operation) {
	switch (operation) {
	case '+':
		return firstNumber + secondNumber;
	case '-':
		return firstNumber - secondNumber;
	case '*':
		return firstNumber * secondNumber;
	case '/':
		if (secondNumber != 0) {
			return firstNumber / secondNumber;
		}
		else {
			cout << "Error: Cannot devide by zero." << endl;
			return numeric_limits<double>::quiet_NaN();
		}
	default:
		cout << "Invalid operator entered: " << endl;
		return numeric_limits<double>::quiet_NaN();
	} 
}

static double getNumber(string prompt) {
	double num;
	while (true) {
		cout << prompt;
		cin >> num;

		if (!cin.fail()) {
			break;
		}
		else {
			cout << "Invalid input. Please enter a valid number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	return num;
}

static bool performAnotherCalculation(){
	char choice;
	while (true) {
		cout << "Do you want to perform another calculation? (y/n): ";
		cin >> choice;

		if (choice == 'Y' || choice == 'y') {
			return true;
		}
		else if (choice == 'N' || choice == 'n') {
			return false;
		}
		else {
			cout << "Invalid input. Please enter 'y' for Yes or 'n' for No." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
}

int main() {
	do {
		double result;
		char operation;

		double firstNumber = getNumber("Enter a first number: ");

		operation = getOperator("Enter an operator('+', '-', '*', '/'): ");

		double secondNumber = getNumber("Enter a second number: ");

		result = calculate(firstNumber, secondNumber, operation);

		cout << "Result: " << result << endl;
	} while (performAnotherCalculation());

	cout << "Thank you for using the calculator!" << endl;

	return 0;
}