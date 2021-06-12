#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> &A, vector<int> &B, vector<vector<int>> &C)
{
    unordered_map<int, vector<int>> g;
    for (int i = 0; i < C.size(); i++)
    {
        g[C[i][0] - 1].push_back(C[i][1] - 1);
        g[C[i][1] - 1].push_back(C[i][0] - 1);
    }
    vector<bool> visited(A.size(), false);
    vector<int> component1;
    vector<int> component2;
    for (int i = 0; i < A.size(); i++)
    {
        if (!visited[i])
        {
            component1.clear();
            component2.clear();
            queue<int> q;
            q.push(i);
            visited[i] = true;
            while (!q.empty())
            {
                int curr = q.front();
                component1.push_back(A[curr]);
                component2.push_back(B[curr]);
                q.pop();
                for (auto v : g[curr])
                {
                    if (!visited[v])
                    {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            sort(component1.begin(), component1.end());
            sort(component2.begin(), component2.end());
            if (component1 != component2)
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];
    int m;
    cin >> m;
    vector<vector<int>> C(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            cin >> C[i][j];

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}