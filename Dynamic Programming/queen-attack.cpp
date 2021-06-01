#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> helper(vector<string> A)
{
    int n = A.size();
    vector<vector<int>> ans(n, vector<int>(n, 0));
    vector<pair<int, int>> dir({{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}});
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] == '1')
            {
                for (auto d : dir)
                {
                    int d_i = i + d.first, d_j = j + d.second;
                    while (d_i >= 0 && d_i < n && d_j >= 0 && d_j < n)
                    {
                        ans[d_i][d_j] += 1;
                        if (A[d_i][d_j] == '1')
                        {
                            break;
                        }
                        d_i += d.first, d_j += d.second;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    auto ans = helper(A);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}