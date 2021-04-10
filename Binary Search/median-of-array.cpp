#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m;
    vector<int> A(m);
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    int target = (m + n + 1) / 2;

    int low = min(m > 0 ? A[0] : -1, n > 0 ? B[0] : -1);
    int high = max(m > 0 ? A[m - 1] : -1, n > 0 ? B[n - 1] : -1);
    double ans = -1.0;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        int count_A = upper_bound(A.begin(), A.end(), mid) - A.begin();
        int count_B = upper_bound(B.begin(), B.end(), mid) - B.begin();
        int total_count = count_A + count_B;
        if (total_count < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    ans = low;
    if ((m + n) % 2 == 0)
    {
        // even
        int t2 = target + 1;
        int l = min(A[0], B[0]);
        int h = max(A[m - 1], B[n - 1]);
        while (l < h)
        {
            int m = l + (h - l) / 2;
            int count_A = upper_bound(A.begin(), A.end(), m) - A.begin();
            int count_B = upper_bound(B.begin(), B.end(), m) - B.begin();
            int total_count = count_A + count_B;
            if (total_count < t2)
            {
                l = m + 1;
            }
            else
            {
                h = m;
            }
        }
        ans = ((float)low + (float)l) / 2;
    }
    cout << ans;
    cout << "\n";

    return 0;
}