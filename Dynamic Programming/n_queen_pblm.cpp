#include <iostream>
using namespace std;

#define N 4

int board[N][N];

bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return false;
    }

    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
            return false;
    }

    for (int i = row - 1, j = col + 1; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

void printBoard()
{
    cout << "Output-\n\n";
    for (int i = 0; i < N; i++)
    {
       
        for (int j = 0; j < N; j++)
        {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";

            
        }
        cout <<"\n";
    }
    cout << endl;
}

void solve(int row)
{
    if (row == N)
    {
        printBoard();
        return;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            board[row][col] = 1;
            solve(row + 1);
            board[row][col] = 0;
        }
    }
}

int main()
{
    solve(0);

    return 0;
}