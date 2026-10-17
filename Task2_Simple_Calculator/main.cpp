
#include <iostream>
#include <limits>
using namespace std;

int main() {
    double num1, num2;
    char op;
    char choice;

    cout << "===== SIMPLE CALCULATOR =====\n";

    do {
        cout << "\nEnter first number: ";
        if (!(cin >> num1)) {
            cout << "Invalid number input!\n";
            return 1;
        }

        cout << "Enter operator (+, -, *, /): ";
        cin >> op;

        cout << "Enter second number: ";
        if (!(cin >> num2)) {
            cout << "Invalid number input!\n";
            return 1;
        }

        switch (op) {
            case '+':
                cout << "Result: " << num1 + num2 << '\n';
                break;

            case '-':
                cout << "Result: " << num1 - num2 << '\n';
                break;

            case '*':
                cout << "Result: " << num1 * num2 << '\n';
                break;

            case '/':
                if (num2 == 0) {
                    cout << "Error: Division by zero is not allowed!\n";
                } else {
                    cout << "Result: " << num1 / num2 << '\n';
                }
                break;

            default:
                cout << "Invalid operator!\n";
        }

        cout << "\nDo you want to calculate again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the calculator!\n";

    return 0;
}
