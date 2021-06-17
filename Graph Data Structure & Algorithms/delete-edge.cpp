#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;

void dfs(int node, int parent, int totalSum, unordered_map<int, vector<int>> &g, vector<long long int> &subtree, int &res)
{
    long long int sum = subtree[node];
    for (auto v : g[node])
    {
        if (v != parent)
        {
            dfs(v, node, totalSum, g, subtree, res);
            sum += subtree[v];
        }
    }
    subtree[node] = sum;
    long long int temp = ((sum % M) * (abs(totalSum - sum) % M)) % M;
    if (temp > res)
    {
        res = temp;
    }
}

int helper(vector<int> A, vector<vector<int>> B)
{
    unordered_map<int, vector<int>> g;
    vector<long long int> subtree(A.size());
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i][0] - 1].push_back(B[i][1] - 1);
        g[B[i][1] - 1].push_back(B[i][0] - 1);
    }

    int totalSum = 0;
    for (int i = 0; i < A.size(); i++)
    {
        totalSum += A[i];
        subtree[i] = A[i];
    }
    int res = INT_MIN;
    dfs(0, -1, totalSum, g, subtree, res);
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
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