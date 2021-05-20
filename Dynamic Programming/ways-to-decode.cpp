#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int helper(string A)
{
    if (A.length() == 0 || A[0] == '0')
        return 0;
    vector<long long int> dp(A.length() + 1, 0);
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= A.length(); i++)
    {
        if (A[i - 1] > '0')
        {
            dp[i] = dp[i - 1];
        }
        if (A[i - 2] == '1' || (A[i - 2] == '2' && A[i - 1] < '7'))
        {
            dp[i] += dp[i - 2];
            dp[i] = dp[i] % M;
        }
    }
    return dp[A.length()];
}

int main()
{
    string A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}