#include <bits/stdc++.h>
using namespace std;

typedef pair<pair<int, int>, int> PII;

class UF
{
private:
    int count;
    vector<int> parent;
    vector<int> size;
    int find(int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

public:
    UF(int n)
    {
        count = n;
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int connectedComponent()
    {
        return count;
    }

    void link(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ)
        {
            return;
        }
        if (size[rootP] > size[rootQ])
        {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        else
        {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        count--;
    }

    bool connected(int p, int q)
    {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }
};

class Compare
{
public:
    bool operator()(PII p1, PII p2)
    {
        return p1.second > p2.second;
    }
};

int helper(int A, vector<vector<int>> &B)
{
    priority_queue<PII, vector<PII>, Compare> edges;
    for (int i = 0; i < B.size(); i++)
    {
        edges.push({{B[i][0] - 1, B[i][1] - 1}, B[i][2]});
    }

    auto uf = new UF(A);
    int edgeCount = 0;
    int src, dst, weight;
    int totalWeight = 0;
    while (edgeCount < A - 1 && !edges.empty())
    {
        auto minEdge = edges.top();
        src = minEdge.first.first, dst = minEdge.first.second, weight = minEdge.second;
        edges.pop();
        if (!uf->connected(src, dst))
        {
            uf->link(src, dst);
            totalWeight += weight;
            edgeCount++;
        }
    }
    return totalWeight;
}

int main()
{
    int A;
    cin >> A;
    int n;
    cin >> n;
    vector<vector<int>> B(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            cin >> B[i][j];

    cout << helper(A, B);

    cout << endl;
    return 0;
}