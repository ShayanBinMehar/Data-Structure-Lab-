#include <iostream>
using namespace std;

const int MAX = 10;

void printBoard(int board[MAX][MAX], int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (board[i][j] ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

bool isSafe(int board[MAX][MAX], int row, int col, int N)
{
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
        if (board[i][j])
            return false;

    return true;
}

void solveNQueens(int board[MAX][MAX], int row, int N, int &count)
{
    if (row == N)
    {
        printBoard(board, N);
        count++;
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col, N))
        {
            board[row][col] = 1;
            solveNQueens(board, row + 1, N, count);
            board[row][col] = 0;
        }
    }
}

int main()
{
    int N;
    cout << "Enter N for N-Queens: ";
    cin >> N;
    if (N < 1 || N > MAX)
    {
        cout << "N must be between 1 and " << MAX << endl;
        return 0;
    }
    int board[MAX][MAX] = {0};
    int count = 0;
    cout << "All possible solutions:\n";
    solveNQueens(board, 0, N, count);
    cout << "Total solutions: " << count << endl;
    return 0;
}