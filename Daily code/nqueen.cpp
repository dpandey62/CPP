#include <iostream>
#include <vector>
using namespace std;

// Function to check if a queen can be placed at (x, y)
bool isSafe(vector<vector<int>> &board, int x, int y, int n)
{
    // Check column above
    for (int i = 0; i < x; i++)
    {
        if (board[i][y] == 1)
            return false;
    }

    // Check left diagonal
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    // Check right diagonal
    for (int i = x, j = y; i >= 0 && j < n; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool solveNQueen(vector<vector<int>> &board, int row, int n)
{
    if (row >= n)
    {
        return true; // All queens are placed
    }

    for (int col = 0; col < n; col++)
    {
        if (isSafe(board, row, col, n))
        {
            board[row][col] = 1; // Place queen

            if (solveNQueen(board, row + 1, n))
                return true;

            board[row][col] = 0; // Backtrack
        }
    }

    return false; // No place for queen in this row
}

// Function to print the board
void printBoard(const vector<vector<int>> &board, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter number of queens (n): ";
    cin >> n;

    // Create an empty board
    vector<vector<int>> board(n, vector<int>(n, 0));

    if (solveNQueen(board, 0, n))
    {
        cout << "One possible solution:\n";
        printBoard(board, n);
    }
    else
    {
        cout << "No solution exists for " << n << " queens.\n";
    }

    return 0;
}
