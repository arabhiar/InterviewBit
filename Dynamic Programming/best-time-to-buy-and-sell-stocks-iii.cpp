#include <bits/stdc++.h>
using namespace std;

// https://github.com/labuladong/fucking-algorithm/blob/english/dynamic_programming/BestTimeToBuyAndSellStock.md
int helper(vector<int> A)
{
    int dp_i_1_0 = 0, dp_i_1_1 = INT_MIN, dp_i_2_0 = 0, dp_i_2_1 = INT_MIN;

    for (int i = 1; i <= A.size(); i++)
    {
        dp_i_2_0 = max(dp_i_2_0, dp_i_2_1 + A[i - 1]);
        dp_i_2_1 = max(dp_i_2_1, dp_i_1_0 - A[i - 1]);
        dp_i_1_0 = max(dp_i_1_0, dp_i_1_1 + A[i - 1]);
        dp_i_1_1 = max(dp_i_1_1, -A[i - 1]);
    }

    return dp_i_2_0;
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