#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A;
        cin >> A;
        vector<int> ans(A + 1, 0);
        ans[0] = 1;
        for (int i = 1; i <= A; i++)
        {
            ans[i] = (ans[i - 1] * (A + 1 - i) / i);
        }
        for (int i = 0; i <= A; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}