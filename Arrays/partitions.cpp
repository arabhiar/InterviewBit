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
        vector<int> B(A);
        for (int i = 0; i < A; i++)
        {
            cin >> B[i];
        }
        int total = 0;
        for (int i = 0; i < A; i++)
        {
            total += B[i];
        }
        int ans = 0;
        if (total % 3 == 0)
        {
            int required = total / 3;
            int t = 0;
            vector<int> index(A, 0);
            for (int i = A - 1; i >= 0; i--)
            {
                t += B[i];
                if (t == required)
                {
                    index[i] = 1;
                }
            }
            for (int i = A - 2; i >= 0; i--)
            {
                index[i] += index[i + 1];
            }
            t = 0;
            for (int i = 0; i < A - 2; i++)
            {
                t += B[i];
                if (t == required)
                {
                    ans += index[i + 2];
                }
            }
        }
        cout << ans;
        cout << endl;
    }
    // system("pause");
    return 0;
}