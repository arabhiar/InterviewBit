#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    int ans = 0;
    int flag = 0;
    stack<char> s;
    for (auto ch : A)
    {
        if (ch == '(')
        {
            s.push(ch);
        }
        else
        {
            while (!s.empty() && s.top() != '(')
            {
                s.pop();
            }
            if (s.empty())
            {
                ans = 0;
                flag = 1;
                break;
            }
            s.pop();
        }
    }
    if (s.empty() && flag == 0)
    {
        ans = 1;
    }

    cout << ans;
    cout << endl;

    return 0;
}