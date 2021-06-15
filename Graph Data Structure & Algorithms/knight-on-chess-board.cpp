#include <bits/stdc++.h>
using namespace std;

int helper(int A, int B, int C, int D, int E, int F)
{
    vector<pair<int, int>> dir({{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}});
    vector<vector<bool>> visited(A, vector<bool>(B, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({{C - 1, D - 1}, 0});
    visited[C - 1][D - 1] = true;
    int minStep = INT_MAX;
    while (!q.empty())
    {
        auto currNode = q.front();
        q.pop();
        int r = currNode.first.first, c = currNode.first.second;
        int step = currNode.second;
        if (r == E - 1 && c == F - 1)
        {
            minStep = min(minStep, step);
        }
        for (auto d : dir)
        {
            int rowIdx = r + d.first, colIdx = c + d.second;
            if (rowIdx >= 0 && rowIdx < A && colIdx >= 0 && colIdx < B && !visited[rowIdx][colIdx])
            {
                visited[rowIdx][colIdx] = true;
                q.push({{rowIdx, colIdx}, step + 1});
            }
        }
    }
    return minStep == INT_MAX ? -1 : minStep;
}

int main()
{
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    cout << helper(A, B, C, D, E, F);

    cout << endl;
    return 0;
}