#include <bits/stdc++.h>
using namespace std;

bool isComplete(vector<vector<char>> A, int &i, int &j)
{
    for (i = 0; i < A.size(); i++)
    {
        for (j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == '.')
            {
                return false;
            }
        }
    }
    return true;
}

bool isSafe(vector<vector<char>> A, int currRow, int currCol, int n)
{
    int row = A.size();
    int col = A[0].size();
    for (int i = 0; i < col; i++)
    {
        if (A[currRow][i] == '0' + n)
        {
            return false;
        }
    }
    for (int i = 0; i < row; i++)
    {
        if (A[i][currCol] == '0' + n)
        {
            return false;
        }
    }

    int boxStartRow = currRow - currRow % 3;
    int boxStartCol = currCol - currCol % 3;
    for (int i = boxStartRow; i < boxStartRow + 3; i++)
    {
        for (int j = boxStartCol; j < boxStartCol + 3; j++)
        {
            if (A[i][j] == '0' + n)
            {
                return false;
            }
        }
    }
    return true;
}

bool backtrack(vector<vector<char>> &A)
{
    int row, col;
    if (isComplete(A, row, col))
    {
        return true;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!isSafe(A, row, col, i))
        {
            continue;
        }
        A[row][col] = i + '0';
        if (backtrack(A))
        {
            return true;
        }
        A[row][col] = '.';
    }
    return false;
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<char>> A(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];
        }
    }

    backtrack(A);

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}