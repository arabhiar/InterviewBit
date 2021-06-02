#include <bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>> A)
{
    int m = A.size(), n = m != 0 ? A[0].size() : 0;
    if (m == 0 || n == 0)
    {
        return 0;
    }
    int ans = 0;
    for (int left = 0; left < n; left++)
    {
        vector<int> colSum(m);
        for (int right = left; right < n; right++)
        {
            for (int i = 0; i < m; i++)
            {
                if (left == right)
                {
                    colSum[i] = A[i][right];
                }
                else
                {
                    colSum[i] += A[i][right];
                }
            }
            int sum;
            for (int up = 0; up < m; up++)
            {
                for (int down = up; down < m; down++)
                {
                    if (up == down)
                    {
                        sum = colSum[down];
                    }
                    else
                    {
                        sum += colSum[down];
                    }
                    if (sum == 0)
                    {
                        ans++;
                    }
                }
            }
        }
    }
    return ans;
}

int main()
{
    int m, n;
    cin >> m >> n;
    vector<vector<int>> A(m, vector<int>(n));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}