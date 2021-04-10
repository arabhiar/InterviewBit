#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    ll ans = INT_MIN;
    stack<int> s;
    vector<ll> rightSpecialVal(A.size());
    s.push(0);
    for (int i = 1; i < A.size(); i++)
    {
        int curr = A[i];
        while (!s.empty() && A[s.top()] < curr)
        {
            rightSpecialVal[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        rightSpecialVal[s.top()] = 0;
        s.pop();
    }

    s.push(A.size() - 1);
    vector<ll> leftSpecialVal(A.size());
    for (int i = A.size() - 2; i >= 0; i--)
    {
        int curr = A[i];
        while (!s.empty() && A[s.top()] < curr)
        {
            leftSpecialVal[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    while (!s.empty())
    {
        leftSpecialVal[s.top()] = 0;
        s.pop();
    }

    for (int i = 0; i < A.size(); i++)
    {
        ans = max(ans, (leftSpecialVal[i] * rightSpecialVal[i]));
    }

    ans = ans % M;
    cout << ans;
    cout << endl;

    return 0;
}