#include <bits/stdc++.h>
using namespace std;

int helper(string A)
{
    int l = A.length();
    vector<vector<int>> dp(l, vector<int>(l, -1));
    for (int i = 0; i < l; i++)
    {
        dp[i][i] = 0;
    }
    for (int block_size = 2; block_size <= l; block_size++)
    {
        for (int left = 0; left <= l - block_size; left++)
        {
            int right = left + block_size - 1;
            if (A[left] == A[right] && (left + 1 == right || dp[left + 1][right - 1] == 0))
            {
                // left and right chars are equal && (either block size is 2 || the substring is a palindrome)

                if (left + 1 == right)
                {
                    dp[left][right] = 0;
                }
                else
                {
                    dp[left][right] = 0;
                }
            }
            else
            {
                int minSplit = INT_MAX;
                for (int split = 0; split < right - left; split++)
                {
                    minSplit = min(minSplit, 1 + dp[left][left + split] + dp[left + split + 1][right]);
                }
                dp[left][right] = minSplit;
            }
        }
    }
    return dp[0][l - 1];
}

int main()
{
    string A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}