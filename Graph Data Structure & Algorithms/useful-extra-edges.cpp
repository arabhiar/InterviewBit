#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PI;

class Compare
{
public:
    bool operator()(PI p1, PI p2)
    {
        return p1.second > p2.first;
    }
};

int helper(int A, vector<vector<int>> &B, int C, int D, vector<vector<int>> &E)
{
    if (C == D)
        return 0;
    unordered_map<int, vector<PI>> g;
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i][0] - 1].push_back({B[i][1] - 1, B[i][2]});
    }
    int minCost = INT_MAX;
    unordered_map<int, vector<PI>> gCopy;
    for (int i = 0; i < E.size(); i++)
    {
        if (E[i][0] > A || E[i][1] > A)
            continue;
        g[E[i][0] - 1].push_back({E[i][1] - 1, E[i][2]});
        g[E[i][1] - 1].push_back({E[i][0] - 1, E[i][2]});
        priority_queue<PI, vector<PI>, Compare> pq;
        vector<int> cost(A, INT_MAX);
        cost[C - 1] = 0;
        pq.push({C - 1, 0});
        while (!pq.empty())
        {
            auto currNode = pq.top();
            pq.pop();
            int src = currNode.first;
            int weight = currNode.second;
            for (auto v : g[src])
            {
                if (v.second + weight < cost[v.first])
                {
                    cost[v.first] = v.second + weight;
                    pq.push({v.first, cost[v.first]});
                }
            }
        }
        minCost = min(minCost, cost[D - 1]);
        g[E[i][0] - 1].pop_back();
        g[E[i][1] - 1].pop_back();
    }
    return minCost == INT_MAX ? -1 : minCost;
}

int main()
{
    int A;
    cin >> A;
    int m;
    cin >> m;
    vector<vector<int>> B(m, (vector<int>(3)));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];
    int C, D;
    cin >> C >> D;
    int n;
    cin >> n;
    vector<vector<int>> E(n, (vector<int>(3)));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> E[i][j];

    cout << helper(A, B, C, D, E);

    cout << endl;
    return 0;
}