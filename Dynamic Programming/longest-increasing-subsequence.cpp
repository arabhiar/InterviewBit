#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    vector<int> dp(A.size(), 1);
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    cout << helper(A);

    cout << endl;
    return 0;
}