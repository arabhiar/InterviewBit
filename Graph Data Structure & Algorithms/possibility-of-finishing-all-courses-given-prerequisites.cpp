#include <bits/stdc++.h>
using namespace std;

// 'W' -> White
// 'G' -> Gray
// 'B' -> Black
vector<char> color;
unordered_map<int, vector<int>> g;

bool isBackEdge(int src)
{
    color[src] = 'G';
    for (auto c : g[src])
    {
        if (color[c] == 'G')
            return true; 
        if (color[c] == 'W' && isBackEdge(c))
            return true;
    }
    color[src] = 'B';
    return false;
}

int helper(int A, vector<int> B, vector<int> C)
{
    color.clear();
    g.clear();
    color.resize(A, 'W');
    for (int i = 0; i < B.size(); i++)
    {
        g[B[i] - 1].push_back(C[i] - 1);
    }
    for (int i = 0; i < A; i++)
    {
        if (color[i] == 'W')
        {
            if (isBackEdge(i))
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int A;
    cin >> A;
    int n;
    cin >> n;
    vector<int> B(n), C(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        cin >> C[i];

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}