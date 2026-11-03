
#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

void displayBoard() {
    cout << "\n";
    cout << "     |     |     \n";
    cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "     |     |     \n\n";
}

bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;
    }

    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;
    }

    // Check diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

int main() {
    char player = 'X';
    int choice;
    int moves = 0;

    cout << "===== TIC-TAC-TOE =====\n";
    cout << "Player X vs Player O\n";

    while (moves < 9) {
        displayBoard();

        cout << "Player " << player
             << ", enter position (1-9): ";

        if (!(cin >> choice)) {
            cout << "Invalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        if (choice < 1 || choice > 9) {
            cout << "Invalid position! Choose from 1 to 9.\n";
            continue;
        }

        int row = (choice - 1) / 3;
        int col = (choice - 1) % 3;

        if (board[row][col] == 'X' ||
            board[row][col] == 'O') {
            cout << "Position already occupied! Try again.\n";
            continue;
        }

        board[row][col] = player;
        moves++;

        if (checkWin(player)) {
            displayBoard();
            cout << "Congratulations! Player "
                 << player << " wins!\n";
            return 0;
        }

        if (player == 'X')
            player = 'O';
        else
            player = 'X';
    }

    displayBoard();
    cout << "It's a draw!\n";

    return 0;
}
