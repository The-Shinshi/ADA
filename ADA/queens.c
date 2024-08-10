#include <stdio.h>
#include <stdbool.h>
#define N 8 // You can change N to any size you need
void printSolution(int board[N][N])
{
    for (int i = 0; i < N; i++, printf("\n"))
        for (int j = 0; j < N; j++)
            printf(" %d ", board[i][j]);
}

bool isSafe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;
    for (int i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;
    return true;
}

bool solveNQ(int board[N][N], int col)
{
    if (col >= N)
        return true;
    for (int i = 0; i < N; i++)
    {
        if (isSafe(board, i, col))
        {
            board[i][col] = 1;
            if (solveNQ(board, col + 1))
                return true;
            board[i][col] = 0; // Backtrack
        }
    }
    return false;
}

int main()
{
    int board[N][N] = {0};
    if (solveNQ(board, 0))
        printSolution(board);
    else
        printf("Solution does not exist");
    return 0;
}