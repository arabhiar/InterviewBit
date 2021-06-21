#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> helper(int A)
{
    int size = 2 * A - 1;
    int start = 0, end = size;
    vector<vector<int>> ans(size, vector<int>(size));
    while (A)
    {
        for (int i = start; i < end; i++)
        {
            for (int j = start; j < end; j++)
            {
                ans[i][j] = A;
            }
        }
        start++;
        end--;
        A--;
    }
    return ans;
}

int main()
{
    int A;
    cin >> A;
    auto ans = helper(A);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[0].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}