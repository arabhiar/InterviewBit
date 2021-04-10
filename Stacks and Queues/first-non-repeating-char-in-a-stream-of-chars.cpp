#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    queue<char> q;
    string ans = "";
    vector<int> freq(26, 0);
    for (auto ch : A)
    {
        freq[ch - 'a']++;
        q.push(ch);
        while (!q.empty() && freq[q.front() - 'a'] > 1)
        {
            q.pop();
        }
        if (q.empty())
        {
            ans += "#";
        }
        else
        {
            ans += q.front();
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}