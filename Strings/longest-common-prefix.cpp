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
    sort(A.begin(), A.end());
    int l = min(A[0].length(), A[n - 1].length());

    string ans = "";
    for (int i = 0; i < l; i++)
    {
        if (A[0][i] == A[n - 1][i])
        {
            ans.push_back(A[0][i]);
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}