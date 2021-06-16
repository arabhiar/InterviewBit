#include <bits/stdc++.h>
using namespace std;

int helper(string A, string B, vector<string> &C)
{
    unordered_set<string> dict(C.begin(), C.end());
    queue<string> q;
    int count = 1;
    q.push(A);
    while (!q.empty())
    {
        int n = q.size();
        for (int k = 0; k < n; k++)
        {
            string curr = q.front();
            q.pop();
            if (curr == B)
            {
                return count;
            }
            dict.erase(curr);
            for (int i = 0; i < curr.size(); i++)
            {
                char c = curr[i];
                for (int j = 0; j < 26; j++)
                {
                    curr[i] = 'a' + j;
                    if (dict.find(curr) != dict.end() || curr == B)
                    {
                        q.push(curr);
                        dict.erase(curr);
                    }
                }
                curr[i] = c;
            }
        }
        count++;
    }
    return 0;
}

int main()
{
    string A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    vector<string> C(n);
    for (int i = 0; i < n; i++)
        cin >> C[i];

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}