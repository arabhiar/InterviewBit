#include <bits/stdc++.h>
using namespace std;

unordered_map<int, vector<int>> g;
vector<char> color;

bool isBackEdge(int src)
{
    color[src] = 'G';
    for (auto v : g[src])
    {
        if (color[v] == 'G')
            return true;
        if (color[v] == 'W' && isBackEdge(v))
            return true;
    }
    color[src] = 'B';
    return false;
}

int helper(int A, vector<vector<int>> B)
{
    g.clear();
    color.clear();
    color.resize(A, 'W');
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i][0] - 1].push_back(B[i][1] - 1);
    }
    for (int i = 0; i < A; i++)
    {
        if (color[i] == 'W')
        {
            if (isBackEdge(i))
                return 1;
        }
    }
    return 0;
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