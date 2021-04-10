#include <bits/stdc++.h>
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

    int ans = 0;
    if (A.size() > 2)
    {
        // maximum element on left and right
        int left_max = 0, right_max = 0;

        // indices to traverse the array
        int lo = 0, hi = n - 1;

        while (lo <= hi)
        {
            if (A[lo] < A[hi])
            {
                if (A[lo] > left_max)
                    // update max in left
                    left_max = A[lo];
                else
                    // water on curr element = max - curr
                    ans += left_max - A[lo];
                lo++;
            }
            else
            {
                if (A[hi] > right_max)
                    // update right maximum
                    right_max = A[hi];
                else
                    ans += right_max - A[hi];
                hi--;
            }
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}