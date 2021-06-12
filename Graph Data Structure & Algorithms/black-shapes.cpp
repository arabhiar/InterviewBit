#include <bits/stdc++.h>
using namespace std;

int helper(vector<string> A)
{
    int n = A.size();
    if (n == 0)
        return 0;
    int m = A[0].size();
    vector<vector<bool>> visited(n, vector<bool> (m, false));
    vector<pair<int, int>> dir({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
    int connectedComponent = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 'X' && visited[i][j] == false)
            {
                connectedComponent++;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    auto curr = q.front();
                    q.pop();
                    for (auto d : dir)
                    {
                        int rowIdx = curr.first + d.first, colIdx = curr.second + d.second;
                        if (rowIdx >= 0 && rowIdx < n && colIdx >= 0 && colIdx < m && A[rowIdx][colIdx] == 'X' && visited[rowIdx][colIdx] == false)
                        {
                            visited[rowIdx][colIdx] = true;
                            q.push({rowIdx, colIdx});
                        }
                    }
                }
            }
        }
    }
    return connectedComponent;
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}