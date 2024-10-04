#include <iostream>

using namespace std;

int main() {
	int firstNumber;
	int secondNumber;
	int result;
	string operation;

	cout << "Enter first number: ";
	cin >> firstNumber;

	cout << "Enter an operator: ";
	cin >> operation;

	cout << "Enter second number: ";
	cin >> secondNumber;

	if (operation == "+") {
		result = firstNumber + secondNumber;
		cout << result;
	}
	else if (operation == "-") {
		result = firstNumber - secondNumber;
		cout << result;
	}
	else if (operation == "*") {
		result = firstNumber * secondNumber;
		cout << result;
	}
	else if (operation == "/") {
		if (secondNumber != 0) {
			result = firstNumber / secondNumber;
			cout << result;
		}
		else {
			cout << "You can not devide by 0.";
		}
	}
	else {
		cout << "You entered the wrong operator. Try again. ";
	}
}