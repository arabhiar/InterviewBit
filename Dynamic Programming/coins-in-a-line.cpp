#include <bits/stdc++.h>
using namespace std;

// https://algorithms.tutorialhorizon.com/dynamic-programming-coin-in-a-line-game-problem/
int helper(vector<int> A)
{
    vector<vector<int>> dp(A.size(), vector<int>(A.size(), 0));
    for (int block_size = 1; block_size <= A.size(); block_size++)
    {
        for (int start = 0; start <= A.size() - block_size; start++)
        {
            int end = start + block_size - 1;
            if (start == end)
            {
                dp[start][end] = A[start];
                continue;
            }
            if (start + 1 == end)
            {
                dp[start][end] = max(A[start], A[end]);
            }
            else
            {
                int option1 = A[start] + min(dp[start + 2][end], dp[start + 1][end - 1]); // possible value if player 2 is playing optimally and i select start index
                int option2 = A[end] + min(dp[start + 1][end - 1], dp[start][end - 2]);  // possible value if player 2 is playing optimally and i select end index
                dp[start][end] = max(option1, option2); // choosing max among bot option
            }
        }
    }
    return dp[0][A.size() - 1];
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