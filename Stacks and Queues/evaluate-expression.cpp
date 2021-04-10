#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    stack<int> s;
    for (auto ch : A)
    {
        if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
        {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            if (ch == "+")
            {
                s.push(second + first);
            }
            else if (ch == "-")
            {
                s.push(second - first);
            }
            else if (ch == "*")
            {
                s.push(second * first);
            }
            else
            {
                s.push(second / first);
            }
        }
        else
        {
            s.push(stoi(ch));
        }
    }
    int ans = s.top();

    cout << ans;
    cout << endl;

    return 0;
}