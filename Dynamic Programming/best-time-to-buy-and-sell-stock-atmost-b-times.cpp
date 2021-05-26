#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, int B)
{
    // dp[i][j][0] => max profit on day i with j remaining transactions and currently not holding any stock
    // dp[i][j][1] => max profit on day i with j remaining transactions and currently holding stock
    if (B <= A.size() / 2)
    {
        vector<vector<vector<int>>> dp(A.size() + 1, vector<vector<int>>(B + 1, vector<int>(2)));
        for (int i = 0; i <= A.size(); i++)
        {
            for (int k = 0; k <= B; k++)
            {
                if (k == 0 || i == 0)
                {
                    // either transaction allowed is 0 or it's 0th day
                    dp[i][k][0] = 0;
                    dp[i][k][1] = INT_MIN;
                }
                else
                {
                    dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + A[i - 1]); // either choose to rest(holding state doesn't change) or he sell the holding today
                    dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - A[i - 1]); // // either choose to rest(holding state doesn't change) or he buy the stock today
                }
            }
        }
        return dp[A.size()][B][0];
    }
    else
    {
        // there are enough transactions
        // hence assuming that we have infinite no of transactions
        vector<vector<int>> dp(A.size() + 1, vector<int>(2));
        for (int i = 0; i <= A.size(); i++)
        {
            if (i == 0)
            {
                // it's 0th day
                dp[i][0] = 0;
                dp[i][1] = INT_MIN;
            }
            else
            {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + A[i - 1]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - A[i - 1]);
            }
        }
        return dp[A.size()][0];
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int B;
    cin >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}