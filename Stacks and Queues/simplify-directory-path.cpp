#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    stack<string> s;
    int count = 0, prevIdx = -1;
    for (int i = 0; i < A.length(); i++)
    {
        string curr = "";
        if (A[i] == '/')
        {
            count++;
            if (prevIdx != -1)
            {
                curr = A.substr(prevIdx + 1, i - prevIdx - 1);
            }
            prevIdx = i;
        }
        if (curr.length() > 0)
        {
            if (curr == "..")
            {
                if (!s.empty())
                    s.pop();
            }
            else
            {
                if (curr != ".")
                {
                    s.push(curr);
                }
            }
        }
    }
    string rem = A.substr(prevIdx + 1);
    if (rem.length() > 0)
    {
        if (rem == "..")
        {
            if (!s.empty())
                s.pop();
        }
        else
        {
            if (rem != ".")
            {
                s.push(rem);
            }
        }
    }
    string ans = "";
    if (s.empty())
    {
        ans = "/";
    }
    vector<string> temp;
    while (!s.empty())
    {
        // cout << s.top() << " ";
        temp.push_back(s.top());
        // ans += s.top() + "/";
        s.pop();
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
    {
        ans += "/" + it;
    }
    // reverse(ans.begin(), ans.end());
    cout << ans;
    cout << endl;

    return 0;
}