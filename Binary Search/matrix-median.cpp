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
    int maxValue = INT_MIN, minValue = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        maxValue = max(A[i][m - 1], maxValue);
        minValue = min(A[i][0], minValue);
    }
    int low = minValue;
    int high = maxValue;
    int element = (n * m + 1) / 2;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            count += (upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin());
        }
        if (count < element)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << low;

    cout << endl;
    return 0;
}