#include <bits/stdc++.h>
using namespace std;

// https://github.com/labuladong/fucking-algorithm/blob/english/dynamic_programming/BestTimeToBuyAndSellStock.md

int helper(vector<int> A)
{
    int dp_i_0 = 0, dp_i_1 = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + A[i]);
        dp_i_1 = max(dp_i_1, temp - A[i]);
    }
    return dp_i_0;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}