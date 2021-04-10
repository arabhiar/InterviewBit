#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int B;
        cin >> B;
        int i = 0;
        int ans = 0;
        int flag = 0;
        while (i < n)
        {
            flag = 0;
            int l = max(0, i - B + 1);
            int r = min(n - 1, i + B - 1);
            for (int k = r; k >= l; k--)
            {
                if (A[k] == 1)
                {
                    i = k + B;
                    ans++;
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                break;
            }
        }
        if (flag == 0)
        {
            cout << -1;
        }
        else
        {
            cout << ans;
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}