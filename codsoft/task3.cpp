#include <iostream>
using namespace std;

// Function to display the Tic Tac Toe board
void displayBoard(char board[]) {
    cout << " " << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "-----------" << endl;
    cout << " " << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "-----------" << endl;
    cout << " " << board[6] << " | " << board[7] << " | " << board[8] << endl;
}

// Function to check if there's a winner
char checkWin(char board[]) {
    int winningCombos[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // Horizontal
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // Vertical
        {0, 4, 8}, {2, 4, 6}              // Diagonal
    };

    for (int i = 0; i < 8; i++) {
        if (board[winningCombos[i][0]] != ' ' &&
            board[winningCombos[i][0]] == board[winningCombos[i][1]] &&
            board[winningCombos[i][0]] == board[winningCombos[i][2]])
            return board[winningCombos[i][0]];
    }

    return ' ';
}

int main() {
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char currentPlayer = 'X';
    int move;
    char winner = ' ';

    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Player 1 (X) - Player 2 (O)\n\n";

    while (winner == ' ') {
        displayBoard(board);

        // Get player's move
        cout << "Player " << currentPlayer << ", enter your move (1-9): ";
        cin >> move;

        // Check if move is valid
        if (move < 1 || move > 9 || board[move - 1] != ' ') {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        board[move - 1] = currentPlayer;

        // Check for a winner
        winner = checkWin(board);

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Display the final board
    displayBoard(board);

    // Declare the winner
    if (winner == 'X' || winner == 'O') {
        cout << "Congratulations! Player " << winner << " wins!\n";
    } else {
        cout << "It's a draw!\n";
    }

    return 0;
}