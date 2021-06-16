#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    unordered_map<int, vector<int>> g;
    int root;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] == -1)
            root = i;
        else
        {
            g[A[i]].push_back(i);
            g[i].push_back(A[i]);
        }
    }
    queue<int> q;
    vector<bool> visited(A.size(), false);
    int farthest;
    q.push(root);
    visited[root] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        farthest = curr;
        for (auto v : g[curr])
        {
            if (!visited[v])
            {
                q.push(v);
                visited[v] = true;
            }
        }
    }
    visited.clear();
    visited.resize(A.size(), false);
    q.push(farthest);
    visited[farthest] = true;
    int levelCount = -1;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            int curr = q.front();
            q.pop();
            for (auto v : g[curr])
            {
                if (!visited[v])
                {
                    q.push(v);
                    visited[v] = true;
                }
            }
        }
        levelCount++;
    }
    return levelCount;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}