#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    unordered_map<char, vector<pair<int, int>>> um;
    int ans = 1;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            if (A[i][j] == '.')
            {
                continue;
            }
            if (um.find(A[i][j]) != um.end())
            {
                // found
                for (auto it : um[A[i][j]])
                {
                    if (it.first == i)
                    {
                        // row having same value
                        ans = 0;
                        break;
                    }
                    if (it.second == j)
                    {
                        // col having same value
                        ans = 0;
                        break;
                    }
                    int rowStart = i - i % 3;
                    int colStart = j - j % 3;
                    if (it.first >= rowStart && it.first < rowStart + 3 && it.second >= colStart && it.second < colStart + 3)
                    {
                        // 3*3 block have same value
                        ans = 0;
                        break;
                    }
                }
            }
            um[A[i][j]].push_back({i, j});
        }
    }

    cout << ans << endl;

    return 0;
}