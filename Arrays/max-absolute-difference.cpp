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
        int ans = 0;
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN, max4 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX, min3 = INT_MAX, min4 = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            max1 = max(max1, A[i] + i);
            max2 = max(max2, -A[i] + i);
            max3 = max(max3, A[i] - i);
            max4 = max(max4, -A[i] - i);

            min1 = min(min1, A[i] + i);
            min2 = min(min2, -A[i] + i);
            min3 = min(min3, A[i] - i);
            min4 = min(min4, -A[i] - i);
        }
        ans = max(ans, max1 - min1);
        ans = max(ans, max2 - min2);
        ans = max(ans, max3 - min3);
        ans = max(ans, max4 - min4);
        cout << ans;
        cout << endl;
    }
    // system("pause");
    return 0;
}