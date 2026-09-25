#include <iostream>
using namespace std;

// Function to print Sudoku board
void printBoard(int board[9][9])
{
    cout << "\n===== SOLVED SUDOKU =====\n";

    for (int row = 0; row < 9; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            cout << board[row][col] << " ";

            if ((col + 1) % 3 == 0)
                cout << " ";
        }

        cout << endl;

        if ((row + 1) % 3 == 0)
            cout << endl;
    }
}

// Check whether number can be placed
bool isSafe(int board[9][9], int row, int col, int number)
{
    // Check row
    for (int i = 0; i < 9; i++)
    {
        if (board[row][i] == number)
            return false;
    }

    // Check column
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == number)
            return false;
    }

    // Find starting position of 3x3 box
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    // Check 3x3 box
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[startRow + i][startCol + j] == number)
                return false;
        }
    }

    return true;
}

// Backtracking function
bool solveSudoku(int board[9][9])
{
    int row = -1;
    int col = -1;

    bool emptyCell = false;

    // Find an empty cell
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == 0)
            {
                row = i;
                col = j;
                emptyCell = true;
                break;
            }
        }

        if (emptyCell)
            break;
    }

    // If no empty cell exists, Sudoku is solved
    if (!emptyCell)
        return true;

    // Try numbers 1 to 9
    for (int number = 1; number <= 9; number++)
    {
        if (isSafe(board, row, col, number))
        {
            // Place number
            board[row][col] = number;

            // Recursively solve remaining cells
            if (solveSudoku(board))
                return true;

            // If solution fails, undo the number
            board[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int board[9][9];

    cout << "===== SUDOKU SOLVER =====\n";

    cout << "Enter Sudoku puzzle.\n";
    cout << "Use 0 for empty cells.\n\n";

    // Input Sudoku
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> board[i][j];
        }
    }

    // Solve Sudoku
    if (solveSudoku(board))
    {
        printBoard(board);
    }
    else
    {
        cout << "\nNo solution exists!\n";
    }

    return 0;
}