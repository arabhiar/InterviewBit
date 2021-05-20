#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;

int helper(int A)
{
    int n = 2 * A;
    vector<long long int> dp(n + 1, 0);
    dp[0] = 1;
    dp[2] = 1;
    for (int i = 4; i < n + 1; i += 2)
    {
        for (int j = 0; j < i - 1; j += 2)
        {
            int set1_points = j;
            int set2_points = i - 2 - j;
            dp[i] += dp[set1_points] * dp[set2_points];
            dp[i] %= M;
        }
    }
    return dp[n];
}

int main()
{
    int A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}