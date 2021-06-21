#include <bits/stdc++.h>
using namespace std;

vector<int> helper(vector<int> A)
{
    int n = A.size();
    vector<int> ans(n, -1);
    if (n == 0)
        return ans;
    stack<int> s;
    s.push(0);
    for (int i = 1; i < n; i++)
    {
        int nextIdx = i;
        while (!s.empty() && A[s.top()] < A[nextIdx])
        {
            int prevIdx = s.top();
            s.pop();
            ans[prevIdx] = A[nextIdx];
        }
        s.push(nextIdx);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    auto ans = helper(A);

    for (int i = 0; i < A.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}