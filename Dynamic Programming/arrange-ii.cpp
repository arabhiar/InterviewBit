#include <bits/stdc++.h>
using namespace std;

// https://codevillage.wordpress.com/2016/09/06/mastering-dynamic-programming-2/
int helper(string A, int B)
{
    int l = A.length();
    if (l < B)
        return -1;
    vector<vector<int>> dp(l, vector<int>(B));
    vector<int> whiteCount(l, 0);
    vector<int> blackCount(l, 0);
    A[0] == 'W' ? whiteCount[0] = 1 : blackCount[0] = 1;
    for (int i = 1; i < l; i++)
    {
        if (A[i] == 'W')
        {
            whiteCount[i] = whiteCount[i - 1] + 1;
            blackCount[i] = blackCount[i - 1];
        }
        else
        {
            blackCount[i] = blackCount[i - 1] + 1;
            whiteCount[i] = whiteCount[i - 1];
        }
    }
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < B; j++)
        {
            if (j == 0)
            {
                dp[i][j] = whiteCount[i] * blackCount[i];
                continue;
            }
            if (i < j)
            {
                dp[i][j] = -1;
                continue;
            }
            int minValue = INT_MAX, currValue;
            for (int k = i - 1; k >= j - 1; k--)
            {
                currValue = dp[k][j - 1] + ((whiteCount[i] - whiteCount[k]) * (blackCount[i] - blackCount[k]));
                minValue = min(minValue, currValue);
            }
            dp[i][j] = minValue;
        }
    }
    return dp[l - 1][B - 1];
}

int main()
{
    string A;
    int B;
    cin >> A >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}