
#include <iostream>
#include <random>
#include <limits>
using namespace std;

int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1, 100);

    int secretNumber = dist(gen);
    int guess;
    int attempts = 0;

    cout << "==============================\n";
    cout << "    NUMBER GUESSING GAME\n";
    cout << "==============================\n";
    cout << "I have selected a number from 1 to 100.\n";
    cout << "Try to guess the number!\n\n";

    while (true) {
        cout << "Enter your guess: ";

        if (!(cin >> guess)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (guess < 1 || guess > 100) {
            cout << "Please enter a number between 1 and 100.\n";
            continue;
        }

        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try a higher number.\n";
        } else if (guess > secretNumber) {
            cout << "Too high! Try a lower number.\n";
        } else {
            cout << "\nCongratulations! You guessed correctly!\n";
            cout << "Number of attempts: " << attempts << '\n';
            break;
        }
    }

    cout << "\nThanks for playing!\n";
    return 0;
}
