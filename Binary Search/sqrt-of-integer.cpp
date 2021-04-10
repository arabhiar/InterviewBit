#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    long long int ans = -1;
    if (A == 1 || A == 0)
    {
        ans = A;
    }
    else
    {
        int low = 1, high = A / 2;
        while (low <= high)
        {
            long long int mid = low + (high - low) / 2;
            long long int currSquare = mid * mid;
            if (currSquare > (long)A)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
                ans = max(ans, mid);
            }
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}