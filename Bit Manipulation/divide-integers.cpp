#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;
    long long int ans = 0;
    if (B == 0 || (A == INT_MIN && B == -1))
    {
        ans = INT_MAX;
    }
    else
    {
        long long int dividend = labs(A), divisor = labs(B);
        int sign = A > 0 ^ B > 0 ? -1 : 1;
        while (dividend >= 0)
        {
            long long int m = 0;
            while (1)
            {
                if (dividend - (divisor << m) < 0)
                {
                    break;
                }
                m++;
            }
            if (m > 0)
            {
                ans += (long long int)1 << (m - 1);
                dividend -= (divisor << m - 1);
            }
            else
            {
                break;
            }
        }
        ans *= sign;
    }
    cout << ans;
    cout << endl;

    return 0;
}