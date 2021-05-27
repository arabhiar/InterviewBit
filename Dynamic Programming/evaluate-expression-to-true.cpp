#include <bits/stdc++.h>
using namespace std;

int M = 1e3+3;

int helper(string A)
{
    vector<vector<int>> dp_true(A.length(), vector<int>(A.length(), 0));
    vector<vector<int>> dp_false(A.length(), vector<int>(A.length(), 0));
    for (int block_size = 1; block_size <= A.size(); block_size += 2)
    {
        for (int left = 0; left <= A.length() - block_size; left++)
        {
            int right = left + block_size - 1;
            if (left == right)
            {
                if (A[left] == 'T')
                {
                    dp_true[left][right] = 1;
                }
                else if (A[left] == 'F')
                {
                    dp_false[left][right] = 1;
                }
            }
            else
            {
                for (int idx = left + 1; idx < right; idx += 2)
                {
                    if (A[idx] == '&')
                    {
                        dp_true[left][right] += (dp_true[left][idx - 1] * dp_true[idx + 1][right]);
                        dp_false[left][right] += (dp_true[left][idx - 1] * dp_false[idx + 1][right]);
                        dp_false[left][right] += (dp_false[left][idx - 1] * dp_true[idx + 1][right]);
                        dp_false[left][right] += (dp_false[left][idx - 1] * dp_false[idx + 1][right]);
                    }
                    else if (A[idx] == '|')
                    {
                        dp_true[left][right] += (dp_true[left][idx - 1] * dp_true[idx + 1][right]);
                        dp_true[left][right] += (dp_true[left][idx - 1] * dp_false[idx + 1][right]);
                        dp_true[left][right] += (dp_false[left][idx - 1] * dp_true[idx + 1][right]);
                        dp_false[left][right] += (dp_false[left][idx - 1] * dp_false[idx + 1][right]);
                    }
                    else if (A[idx] == '^')
                    {
                        dp_false[left][right] += (dp_true[left][idx - 1] * dp_true[idx + 1][right]);
                        dp_true[left][right] += (dp_true[left][idx - 1] * dp_false[idx + 1][right]);
                        dp_true[left][right] += (dp_false[left][idx - 1] * dp_true[idx + 1][right]);
                        dp_false[left][right] += (dp_false[left][idx - 1] * dp_false[idx + 1][right]);
                    }
                    dp_true[left][right] %= M;
                    dp_false[left][right] %= M;
                }
            }
        }
    }
    return dp_true[0][A.length() - 1];
}

int main()
{
    string A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}