#include <bits/stdc++.h>
using namespace std;

bool isValid(int &i, int &j, int &A, int &B)
{
    return (i >= 0 && i < A && j >= 0 && j < B);
}

int helper(vector<vector<int>> A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    vector<pair<int, int>> dir({{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}});
    int maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 1 && visited[i][j] == false)
            {
                int count = 1;
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty())
                {
                    auto curr = q.front();
                    q.pop();
                    for (auto d : dir)
                    {
                        int xIdx = curr.first + d.first, yIdx = curr.second + d.second;
                        if (isValid(xIdx, yIdx, n, m) && visited[xIdx][yIdx] == false && A[xIdx][yIdx] == 1)
                        {
                            q.push({xIdx, yIdx});
                            visited[xIdx][yIdx] = true;
                            count++;
                        }
                    }
                }
                maxCount = max(maxCount, count);
            }
        }
    }
    return maxCount;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}