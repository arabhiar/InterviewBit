#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A;
        cin >> A;
        vector<vector<int>> ans(A);
        if (A == 0)
        {
        }
        else
        {
            ans[0].push_back(1);
            ans[1].push_back(1);
            ans[1].push_back(1);
            for (int i = 2; i < A; i++)
            {
                ans[i].push_back(1);
                // ans[i][i] = 1;
                for (int j = 1; j < i; j++)
                {
                    ans[i].push_back(ans[i - 1][j - 1] + ans[i - 1][j]);
                }
                ans[i].push_back(1);
            }
        }

        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}