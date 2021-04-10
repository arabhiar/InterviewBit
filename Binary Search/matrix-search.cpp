#include <bits/stdc++.h>
using namespace std;

int main()

{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> A[i][j];
        }
    }
    int B;
    cin >> B;
    // n = A.size();
    // m = A[0].size();
    int start = 0, end = n - 1;
    int row_idx = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (B >= A[mid][0] && B <= A[mid][m - 1])
        {
            row_idx = mid;
            break;
        }
        if (A[mid][0] < B)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    int col_idx = -1;
    if (row_idx != -1)
    {
        start = 0;
        end = m - 1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (B == A[row_idx][mid])
            {
                col_idx = mid;
                break;
            }
            if (A[row_idx][mid] < B)
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    int ans = 0;
    if (col_idx != -1)
    {
        ans = 1;
    }
    cout << ans;
    cout << "\n";
    return 0;
}