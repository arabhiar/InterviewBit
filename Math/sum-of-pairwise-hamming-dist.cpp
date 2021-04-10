#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

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
        const int noOfBits = sizeof(A[0]) * 8;
        // const int noOfBits = 4;
        long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            long count_0, count_1 = 0;
            for (int j = 0; j < n; j++)
            {
                if ((A[j] & (1 << i)))
                {
                    count_1++;
                }
            }
            count_0 = n - count_1;
            ans += (count_0 * count_1 * 2);
        }
        cout << ans % M;
        cout << endl;
    }
    return 0;
}