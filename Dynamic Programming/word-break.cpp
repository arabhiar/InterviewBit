#include <bits/stdc++.h>
using namespace std;

bool helper(string A, vector<string> B)
{
    unordered_set<string> s;
    for (auto word : B)
        s.insert(word);
    int l = A.length();
    vector<bool> dp(l + 1, false);
    dp[0] = true;
    for (int block_size = 1; block_size <= l; block_size++)
    {
        for (int split = block_size - 1; split >= 0; split--)
        {
            if (dp[split])
            {
                string currWord = A.substr(split, block_size - split);
                if (s.find(currWord) != s.end())
                {
                    dp[block_size] = true;
                    break;
                }
            }
        }
    }
    return dp[l];
}

int main()
{
    string A;
    cin >> A;
    int n;
    cin >> n;
    vector<string> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << helper(A, B);

    cout << endl;
    return 0;
}