#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

using namespace std;

// Function declarations
void displayBoard(char *board);
int checkForWin(char *board);
void makeMove(char *board, int choice, char symbol);
void gotoxy(int x, int y);
void load();
void showRules();
void getPlayerNames(string &player1, string &player2);
void decideSymbols(char &symbol1, char &symbol2, const string &player1);
void playGame(char *board, const string &player1, const string &player2, char symbol1, char symbol2);

// Function to set the cursor position
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Loading animation
void load() {
    system("COLOR F5");
    gotoxy(50, 14);
    cout << "Loading...";
    gotoxy(49, 15);
    for (int r = 1; r <= 12; r++) {
        Beep(659, 100);
        cout << (char)177;
    }
    gotoxy(45, 20);
    cout << "Press any key to continue...";
    getch();
    system("cls");
}

// Function to display the rules
void showRules() {
    cout << "\tTic-Tac-Toe\n\n";
    cout << "Welcome to the fun 2-player game using X and O\n\n";
    cout << "Rules:\n";
    cout << "1: This is a 2-player game where each player takes turns to place their symbol (X or O).\n";
    cout << "2: The game is played on a 3x3 grid where each cell is numbered 1-9.\n";
    cout << "3: Upon entering the number, the corresponding cell will be filled with the player's symbol.\n";
    cout << "4: The player who succeeds in placing three of their symbols in a horizontal, vertical, or diagonal row wins.\n";
    cout << "5: If all cells are filled and no player has won, the game is declared a draw.\n\n";
    cout << "Enjoy the game! Be a Winner!\n\n";
    cout << "Press any key to continue...";
    getch();
    system("cls");
}

// Function to check for a win or draw
int checkForWin(char *board) {
    // Winning combinations
    int wins[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Columns
        {0, 4, 8}, {2, 4, 6}             // Diagonals
    };

    for (int i = 0; i < 8; i++) {
        if (board[wins[i][0]] == board[wins[i][1]] && board[wins[i][1]] == board[wins[i][2]]) {
            return 1; // Win
        }
    }

    // Check for draw (no empty spots)
    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return -1; // Game continues
        }
    }
    return 0; // Draw
}

// Function to display the game board
void displayBoard(char *board) {
    system("cls");
    cout << "\tTic-Tac-Toe\n\n";
    cout << "  " << board[0] << " |  " << board[1] << " | " << board[2] << "\n";
    cout << "----|----|----\n";
    cout << "  " << board[3] << " |  " << board[4] << " | " << board[5] << "\n";
    cout << "----|----|----\n";
    cout << "  " << board[6] << " |  " << board[7] << " | " << board[8] << "\n";
}

// Function to make a move
void makeMove(char *board, int choice, char symbol) {
    if (choice >= 1 && choice <= 9) {
        board[choice - 1] = symbol;
    }
}

// Function to get player names
void getPlayerNames(string &player1, string &player2) {
    do {
        cout << "Enter name of player 1: ";
        cin >> player1;
        cout << "Enter name of player 2: ";
        cin >> player2;

        if (player1 == player2) {
            cout << "Enter names of different players!\n\n";
        }
    } while (player1 == player2);
}

// Function to decide which player uses which symbol
void decideSymbols(char &symbol1, char &symbol2, const string &player1) {
    char decision;
    do {
        cout << player1 << ", choose 'X' or 'O': ";
        cin >> decision;
    } while (decision != 'X' && decision != 'O' && decision != 'x' && decision != 'o');

    if (decision == 'X' || decision == 'x') {
        symbol1 = 'X';
        symbol2 = 'O';
    } else {
        symbol1 = 'O';
        symbol2 = 'X';
    }
}

// Function to play the game
void playGame(char *board, const string &player1, const string &player2, char symbol1, char symbol2) {
    int playerTurn = 1;
    int choice;
    int gameState = -1;
    char symbol;

    do {
        displayBoard(board);
        symbol = (playerTurn == 1) ? symbol1 : symbol2;

        cout << "\n" << ((playerTurn == 1) ? player1 : player2) << "'s turn (" << symbol << "). Enter a number (1-9): ";
        cin >> choice;

        if (choice >= 1 && choice <= 9 && board[choice - 1] != 'X' && board[choice - 1] != 'O') {
            makeMove(board, choice, symbol);
            gameState = checkForWin(board);
            playerTurn = (playerTurn % 2) + 1;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    } while (gameState == -1);

    displayBoard(board);

    if (gameState == 1) {
        cout << "\n" << ((playerTurn == 1) ? player2 : player1) << " wins!\n";
    } else {
        cout << "\nIt's a draw!\n";
    }
}

// Main function
int main() {
    system("COLOR F5");
    gotoxy(45, 14);
    cout << "WELCOME TO THE 2 PLAYERS TIC-TAC-TOE GAME";
    gotoxy(48, 16);
    cout << "Press any key to know the rules...";
    getch();
    system("cls");

    showRules();
    load();

    char board[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string player1, player2;
    char symbol1, symbol2;

    getPlayerNames(player1, player2);
    decideSymbols(symbol1, symbol2, player1);
    playGame(board, player1, player2, symbol1, symbol2);

    return 0;
}

