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
    int ans = INT_MIN;
    int i;
    for (i = 0; i < A.size(); i++)
    {
        int currHeight = A[i];
        while (!s.empty() && currHeight <= A[s.top()])
        {
            int temp = s.top();
            s.pop();
            int right = i;
            int left = s.empty() ? -1 : s.top();
            ans = max(ans, A[temp] * (right - left - 1));
        }
        s.push(i);
    }
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        int right = i;
        int left = s.empty() ? -1 : s.top();
        ans = max(ans, A[temp] * (right - left - 1));
    }

    cout << ans;
    cout << endl;

    return 0;
}