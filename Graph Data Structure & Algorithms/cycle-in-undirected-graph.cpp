#include <bits/stdc++.h>
using namespace std;

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

int helper(int A, vector<vector<int>> &B)
{
    auto uf = new UF(A);
    int src, dst;
    for (int i = 0; i < B.size(); i++)
    {
        src = B[i][0] - 1, dst = B[i][1] - 1;
        if (uf->connected(src, dst))
        {
            return 1;
        }
        else
        {
            uf->link(src, dst);
        }
    }
    return 0;
}

int main()
{
    int A;
    cin >> A;
    int n;
    cin >> n;
    vector<vector<int>> B(n, vector<int>(3));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> B[i][j];

    cout << helper(A, B);

    cout << endl;
    return 0;
}