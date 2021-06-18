#include <bits/stdc++.h>
using namespace std;

void helper(vector<vector<char>> &A)
{
    int r = A.size(), c = A[0].size();
    vector<vector<bool>> visited(r, vector<bool>(c, false));
    queue<pair<int, int>> q;
    vector<pair<int, int>> dir{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    for (int i = 0; i < c; i++)
    {
        if (A[0][i] == 'O' && !visited[0][i])
        {
            q.push({0, i});
            visited[0][i] = true;
            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                for (auto d : dir)
                {
                    int rowIdx = curr.first + d.first, colIdx = curr.second + d.second;
                    if (rowIdx >= 0 && rowIdx < r && colIdx >= 0 && colIdx < c && A[rowIdx][colIdx] == 'O' && !visited[rowIdx][colIdx])
                    {
                        q.push({rowIdx, colIdx});
                        visited[rowIdx][colIdx] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        if (A[i][c - 1] == 'O' && !visited[i][c - 1])
        {
            q.push({i, c - 1});
            visited[i][c - 1] = true;
            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                for (auto d : dir)
                {
                    int rowIdx = curr.first + d.first, colIdx = curr.second + d.second;
                    if (rowIdx >= 0 && rowIdx < r && colIdx >= 0 && colIdx < c && A[rowIdx][colIdx] == 'O' && !visited[rowIdx][colIdx])
                    {
                        q.push({rowIdx, colIdx});
                        visited[rowIdx][colIdx] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < c; i++)
    {
        if (A[r - 1][i] == 'O' && !visited[r - 1][i])
        {
            q.push({r - 1, i});
            visited[r - 1][i] = true;
            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                for (auto d : dir)
                {
                    int rowIdx = curr.first + d.first, colIdx = curr.second + d.second;
                    if (rowIdx >= 0 && rowIdx < r && colIdx >= 0 && colIdx < c && A[rowIdx][colIdx] == 'O' && !visited[rowIdx][colIdx])
                    {
                        q.push({rowIdx, colIdx});
                        visited[rowIdx][colIdx] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        if (A[i][0] == 'O' && !visited[i][0])
        {
            q.push({i, 0});
            visited[i][0] = true;
            while (!q.empty())
            {
                auto curr = q.front();
                q.pop();
                for (auto d : dir)
                {
                    int rowIdx = curr.first + d.first, colIdx = curr.second + d.second;
                    if (rowIdx >= 0 && rowIdx < r && colIdx >= 0 && colIdx < c && A[rowIdx][colIdx] == 'O' && !visited[rowIdx][colIdx])
                    {
                        q.push({rowIdx, colIdx});
                        visited[rowIdx][colIdx] = true;
                    }
                }
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (A[i][j] == 'O' && !visited[i][j])
            {
                A[i][j] = 'X';
            }
        }
    }
}

int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<char>> A(r, vector<char>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> A[i][j];

    helper(A);

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}