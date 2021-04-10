#include<bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    stack<char> s;
    int ans = 0;
    for (auto ch : A)
    {
        if (ch == ')')
        {
            if (s.top() == '(')
            {
                ans = 1;
            }
            else
            {
                int op = 0;
                while (s.top() != '(')
                {
                    if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
                    {
                        op = 1;
                    }
                    s.pop();
                }
                s.pop();
                if (!op)
                {
                    ans = 1;
                    break;
                }
            }
        }
        else
        {
            s.push(ch);
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}