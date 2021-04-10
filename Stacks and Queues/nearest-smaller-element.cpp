#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    stack<int> s;
    vector<int> ans(A.size());
    s.push(A.size() - 1);
    for (int i = A.size() - 2; i >= 0; i--)
    {
        int curr = A[i];
        while (!s.empty() && A[s.top()] > curr)
        {
            ans[s.top()] = curr;
            s.pop();
        }
        s.push(i);
    }
    while (!s.empty())
    {
        ans[s.top()] = -1;
        s.pop();
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}