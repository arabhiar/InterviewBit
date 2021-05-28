#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> vec)
{
    if (vec.size() == 0)
    {
        return 0;
    }
    int maxSoFar = vec[0];
    int maxEndingHere = vec[0];
    for (int i = 1; i < vec.size(); i++)
    {
        maxEndingHere = max(maxEndingHere + vec[i], vec[i]);
        if (maxEndingHere > maxSoFar)
        {
            maxSoFar = maxEndingHere;
        }
    }
    return maxSoFar;
}

int helper(vector<vector<int>> A)
{
    int n = A.size(), m = A[0].size();
    vector<int> sumArr(n);
    int maxSum = INT_MIN;
    for (int i = m - 1; i >= 0; i--)
    {
        if (i == m - 1)
        {
            for (int j = 0; j < n; j++)
            {
                sumArr[j] = A[j][i];
            }
        }
        else
        {
            for (int j = 0; j < n; j++)
            {
                sumArr[j] += A[j][i];
            }
        }
        maxSum = max(maxSum, kadane(sumArr));
    }
    return maxSum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}