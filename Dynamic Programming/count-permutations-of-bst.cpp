#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;

void comb(vector<vector<long long int>> &c)
{
    c[0][0] = 1;
    for (int i = 1; i < c.size(); i++)
    {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
        {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            c[i][j] = c[i][j] % M;
        }
    }
}

int helper(int A, int B)
{
    vector<vector<long long int>> dp(A + 1, vector<long long int>(B + 1, 0));
    vector<vector<long long int>> c(A + 1, vector<long long int>(A + 1, 0));
    dp[0][0] = dp[1][0] = 1;
    comb(c);
    for (int i = 2; i <= A; i++)
    {
        for (int j = 1; j <= B; j++)
        {
            for (int x = 1; x <= i; x++)
            {
                int a = x - 1, b = i - x;
                long long int v1 = 0, v2 = 0, v3 = 0, v = 0;
                // case 1: only left child is of height i-1.
                for (int h = 0; h < j - 1; h++)
                {
                    v1 += dp[a][j - 1] * dp[b][h];
                    v1 %= M;
                }
                // case 2: only right child is of height i-1.
                for (int h = 0; h < j - 1; h++)
                {
                    v2 += dp[b][j - 1] * dp[a][h];
                    v2 %= M;
                }
                // case 3: both child are of height i-1.
                v3 += dp[a][j - 1] * dp[b][j - 1];
                v3 %= M;
                v = v1 + v2 + v3;
                v %= M;
                dp[i][j] += (v * c[a + b][b]) % M;
                // cout << "\n@ comb=>" << c[a + b][b] << " v=>" << v << " i=>" << i << " j=>" << j << " x=>" << x << " dp[i][j]=> " << dp[i][j] << endl;
                dp[i][j] %= M;
            }
        }
    }
    return dp[A][B];
}

int main()
{
    int A, B;
    cin >> A >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}