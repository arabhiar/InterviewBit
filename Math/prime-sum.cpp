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
        vector<int> ans(2, 0);
        // float l = ceil(sqrt(A));
        // int n = (int)l;
        int n = A / 2;
        for (int i = 2; i <= n; i++)
        {
            int count = 0;
            for (int j = 1; j <= i; j++)
            {
                if (i % j == 0)
                {
                    count++;
                }
            }
            if (count == 2)
            {
                int count2 = 0;
                for (int j = 1; j <= A - i; j++)
                {
                    if ((A - i) % j == 0)
                    {
                        count2++;
                    }
                }
                if (count2 == 2)
                {
                    ans[0] = i;
                    ans[1] = A - i;
                    break;
                }
            }
        }
        cout << ans[0] << " " << ans[1];
        cout << endl;
    }
    return 0;
}