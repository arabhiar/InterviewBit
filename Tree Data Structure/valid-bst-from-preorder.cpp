#include<bits/stdc++.h>
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

    int ans = 1;
    stack<int> s;
    int root = INT_MIN;
    for (auto node : A)
    {
        while (!s.empty() && node > s.top())
        {
            root = s.top();
            s.pop();
        }
        if (node < root)
        {
            ans = 0;
            break;
        }
        s.push(node);
    }

    cout << ans << endl;

    return 0;
}