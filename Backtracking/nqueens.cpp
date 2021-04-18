#include <bits/stdc++.h>
using namespace std;

bool isSafe(vector<string> state, int i, int j)
{
    int row = state.size();
    int col = state[0].size();
    int row_i = i, col_j = j;
    while (row_i >= 0 && col_j >= 0)
    {
        if (state[row_i][col_j] == 'Q')
        {
            return false;
        }
        row_i--;
        col_j--;
    }
    row_i = i;
    col_j = j;
    while (row_i >= 0 && col_j < col)
    {
        if (state[row_i][col_j] == 'Q')
        {
            return false;
        }
        row_i--;
        col_j++;
    }
    row_i = i;
    col_j = j;
    while (row_i >= 0)
    {
        if (state[row_i][col_j] == 'Q')
        {
            return false;
        }
        row_i--;
    }
    return true;
}

void backtrack(vector<vector<string>> &res, vector<string> &track, int currRow, int A)
{
    if (currRow == A)
    {
        res.push_back(track);
        return;
    }
    for (int i = 0; i < A; i++)
    {
        if (!isSafe(track, currRow, i))
        {
            continue;
        }
        track[currRow][i] = 'Q';
        backtrack(res, track, currRow + 1, A);
        track[currRow][i] = '.';
    }
}

int main()
{
    int A;
    cin >> A;

    vector<vector<string>> res;
    vector<string> track(A, string(A, '.'));
    backtrack(res, track, 0, A);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << endl;
        }
        cout << endl;
    }

    return 0;
}