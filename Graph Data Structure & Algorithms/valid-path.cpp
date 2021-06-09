#include <bits/stdc++.h>
using namespace std;

bool isValid(int &i, int &j, int &A, int &B)
{
    return (i >= 0 && i <= A && j >= 0 && j <= B);
}

string helper(int A, int B, int C, int D, vector<int> &E, vector<int> &F)
{
    vector<pair<int, int>> dir8({{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}});
    vector<pair<int, int>> dir4({{-1, 0}, {0, 1}, {1, 0}, {0, -1}});
    vector<pair<int, int>> dir({{0, 1}, {1, 1}, {1, 0}});
    vector<vector<bool>> blocked(A + 1, vector<bool>(B + 1, false));
    for (int i = 0; i <= A; i++)
    {
        for (int j = 0; j <= B; j++)
        {
            for (int k = 0; k < C; k++)
            {
                int x = abs(i - E[k]), y = abs(j - F[k]);
                if (sqrt(pow(x, 2) + pow(y, 2)) <= D)
                {
                    blocked[i][j] = true;
                }
            }
        }
    }
    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited.insert({0, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        if (curr == make_pair(A, B))
        {
            return "YES";
        }
        for (auto d : dir8)
        {
            int xIdx = curr.first + d.first, yIdx = curr.second + d.second;
            if (isValid(xIdx, yIdx, A, B) && visited.find({xIdx, yIdx}) == visited.end() && blocked[xIdx][yIdx] == false)
            {
                q.push({xIdx, yIdx});
                visited.insert({xIdx, yIdx});
            }
        }
    }
    return "NO";
}

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    vector<int> E(C), F(C);
    for (int i = 0; i < C; i++)
    {
        cin >> E[i];
    }
    for (int i = 0; i < C; i++)
    {
        cin >> F[i];
    }

    cout << helper(A, B, C, D, E, F);

    cout << endl;
    return 0;
}