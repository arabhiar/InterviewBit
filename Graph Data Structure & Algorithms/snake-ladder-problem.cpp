#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> &A, vector<vector<int>> &B)
{
    unordered_map<int, vector<int>> g;
    for (int i = 1; i <= 100; i++)
    {
        for (int j = 1; j <= 6; j++)
        {
            if (i + j <= 100)
                g[i].push_back(i + j);
        }
    }
    unordered_set<int> snakeAndLadderStartPos;
    for (int i = 0; i < A.size(); i++)
    {
        g[A[i][0]].clear();
        g[A[i][0]].push_back(A[i][1]);
        snakeAndLadderStartPos.insert(A[i][0]);
    }
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i][0]].clear();
        g[B[i][0]].push_back(B[i][1]);
        snakeAndLadderStartPos.insert(B[i][0]);
    }
    queue<pair<int, int>> q;
    unordered_set<int> visited;
    q.push({1, 0});
    visited.insert(1);
    int minRoll = -1;
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        int rollCount = curr.second;
        if (curr.first == 100)
        {
            minRoll = max(minRoll, rollCount);
        }
        for (auto node : g[curr.first])
        {
            if (visited.find(node) == visited.end())
            {
                visited.insert(node);
                if (snakeAndLadderStartPos.find(node) != snakeAndLadderStartPos.end())
                    q.push({node, rollCount});
                else
                    q.push({node, rollCount + 1});
            }
        }
    }
    return minRoll;
}

int main()
{
    int m, n;
    cin >> m;
    vector<vector<int>> A(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];
    cin >> n;
    vector<vector<int>> B(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    cout << helper(A, B);

    cout << endl;
    return 0;
}