/*
 * Name: Noah Lacorazza
 * Program: Terminal Battleship Game (SKELETON CODE)
 * Description: A very rudamentary version of Battleship. Player guesses the coordinates of hidden ships on a given grid.
 * The game ends when all ships are sunk. The player can also use bombs to hit multiple cells at once, but has a limited number of bombs.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 6 // Board size
#define SHIPS 5 // Number of ships
#define BOMBS 5 // Number of bombs

// Function declarations
void initializeBoard(int board[SIZE][SIZE][2]);
void displayBoard(int board[SIZE][SIZE][2], int revealShips);
int alreadyGuessed(int col, int row, int board[SIZE][SIZE][2]);
int isShip(int col, int row, int board[SIZE][SIZE][2]);
int useBomb(int centerCol, int centerRow, int board[SIZE][SIZE][2]);

// MAIN GAME LOGIC
int main() {
    int board[SIZE][SIZE][2];
    int row, col;

    int attempts = 0; // Count of attempts
    int hits = 0;     // Count of hits
    int bombsLeft = BOMBS; // Count of bombs left

    srand(time(NULL)); // random seed

    initializeBoard(board); // Initialize the game board

    printf("Welcome to Terminal Battleship!\n\n");
    printf("Controls: 'g|b row col' to make a guess or use a bomb, 'q' to quit.\n");
    printf("Ex: 'g 2 3' to guess row 2, column 3. 'b 4 4' to use a bomb at row 4, column 4.\n\n");

    while (hits < SHIPS) {
        displayBoard(board, 0); // Display the board without revealing ships

        char command;
        printf("Enter your command (%d bombs): ", bombsLeft);
        scanf(" %c", &command);

        if (command == 'q')
            return 0; // Exit the game

        scanf(" %d %d", &row, &col); // Read row and column for guess
        printf("\n");

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) { // Check boundaries
            printf("Invalid coordinates! Please enter values between 0 and %d.\n", SIZE - 1);
            continue; // Skip to the next iteration
        }

        if (command == 'g') {
            if (alreadyGuessed(col, row, board)) { // Check if already guessed
                printf("You've already guessed that position!\n");
                continue; // Skip to the next iteration
            } else {
                board[col][row][0] = 1; // Mark cell as revealed
                attempts++;

                if (isShip(col, row, board)) { // Check if it's a hit
                    printf("Hit!\n");
                    hits++;
                } else {
                    printf("Miss!\n");
                }
            }
        } else if (command == 'b') {
            if (bombsLeft <= 0) {
                printf("No bombs left!\n");
                continue; // Skip to the next iteration
            } else {
                bombsLeft--;
                int bombHits = useBomb(col, row, board); // Use bomb and get hits
                hits += bombHits; // Update total hits
                attempts++; // Count bomb usage as an attempt

                printf("Bomb used! Hits in bomb area: %d\n", bombHits);
            }
        } else {
            printf("Invalid command! Please enter 'g', 'b', or 'q'.\n");
            continue; // Skip to the next iteration
        }
    }

    displayBoard(board, 1); // Display the board with ships revealed

    printf("\nCongratulations! All ships sunk in %d attempts.\n", attempts);

    return 0;
}

// Initialize board with '~'
void initializeBoard(int board[SIZE][SIZE][2]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j][0] = 0; // Initialize revealed status to 0
            board[i][j][1] = 0; // Initialize ship presence to 0
        }
    }

    // Place ships randomly
    int placedShips = 0;
    while (placedShips < SHIPS) {
        int randRow = rand() % SIZE; // Random row between 0 and SIZE - 1
        int randCol = rand() % SIZE; // Random column between 0 and SIZE - 1
        if (board[randRow][randCol][1] == 0) { // Check if no ship is already placed
            board[randRow][randCol][1] = 1; // Place ship
            placedShips++;
        }
    }
}

// Display the board
void displayBoard(int board[SIZE][SIZE][2], int revealShips) {
    printf("  0 1 2 3 4 5\n"); // Print column numbers

    for (int i = 0; i < SIZE; i++) {
        printf("%d ", i); // Print row number

        for (int j = 0; j < SIZE; j++) {
            if (!revealShips && board[i][j][0] == 0) { // Not revealed
                printf("~ ");
            } else if (board[i][j][1] == 1) { // Ship hit
                printf("X ");
            } else { // Miss
                printf("O ");
            }
        }

        printf("\n");
    }

    printf("\n");
}

// Check if cell already guessed
int alreadyGuessed(int col, int row, int board[SIZE][SIZE][2]) {
    return board[col][row][0]; // Return 1 if already guessed, else 0
}

// Check if ship is at cell
int isShip(int col, int row, int board[SIZE][SIZE][2]) {
    return board[col][row][1]; // Return 1 if ship is present, else 0
}

// Bomb hits 3x3 area
int useBomb(int centerCol, int centerRow, int board[SIZE][SIZE][2]) {
    int hits = 0;

    for (int i = centerCol - 1; i <= centerCol + 1; i++) {
        for (int j = centerRow - 1; j <= centerRow + 1; j++) {
            // Check boundaries
            if (i >= 0 && i < SIZE && j >= 0 && j < SIZE) {
                // Skip already guessed cells
                if (!alreadyGuessed(i, j, board)) {
                    board[i][j][0] = 1; // Mark cell as revealed

                    if (board[i][j][1] == 1) { // Check if it's a hit
                        hits++;
                    }
                }
            }
        }
    }

    return hits; // Return the number of hits in the bomb area
}