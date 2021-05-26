#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> helper(int A, vector<vector<int>> B)
{
    int row = B.size();
    int col = B[0].size();
    vector<vector<int>> currMax = B, nextMax = B;
    for (int k = 0; k < A; k++)
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int curr = B[i][j];
                int top = (i == 0) ? INT_MIN : currMax[i - 1][j];
                int right = (j == col - 1) ? INT_MIN : currMax[i][j + 1];
                int bottom = (i == row - 1) ? INT_MIN : currMax[i + 1][j];
                int left = (j == 0) ? INT_MIN : currMax[i][j - 1];
                nextMax[i][j] = max(max(top, right), max(max(bottom, left), curr));
            }
        }
        currMax = nextMax;
    }
    return currMax;
}

int main()
{
    int A, n, m;
    cin >> A >> n >> m;
    vector<vector<int>> B(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> B[i][j];

    auto ans = helper(A, B);

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }

    cout << endl;

    return 0;
}