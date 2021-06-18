#include <bits/stdc++.h>
using namespace std;

int helper(int A, vector<vector<int>> &B)
{
    vector<vector<int>> g(A);
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i][0] - 1].push_back(B[i][1] - 1);
        g[B[i][1] - 1].push_back(B[i][0] - 1);
    }
    vector<int> color(A, -1);
    queue<int> q;
    for (int i = 0; i < A; i++)
    {
        if (color[i] == -1)
        {
            q.push(i);
            color[i] = 0;
            while (!q.empty())
            {
                int curr = q.front();
                q.pop();
                for (auto v : g[curr])
                {
                    if (color[v] == -1)
                    {
                        color[v] = color[curr] ^ 1;
                        q.push(v);
                    }
                    else if (color[v] == color[curr])
                    {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

int main()
{
    int A;
    cin >> A;
    int m;
    cin >> m;
    vector<vector<int>> B(m, vector<int>(2));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    cout << helper(A, B);

    cout << endl;
    return 0;
}