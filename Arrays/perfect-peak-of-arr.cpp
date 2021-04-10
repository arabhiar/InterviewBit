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
        vector<int> leftMax(n);
        vector<int> rightMin(n);
        leftMax[0] = A[0];
        rightMin[n - 1] = A[n - 1];
        for (int i = 1; i < n; i++)
        {
            leftMax[i] = max(A[i], leftMax[i - 1]);
        }
        for (int i = n - 2; i >= 0; i--)
        {
            rightMin[i] = min(rightMin[i + 1], A[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++)
        {
            if (A[i] > leftMax[i - 1] && A[i] < rightMin[i + 1])
            {
                ans = 1;
            }
        }
        cout << ans;
        cout << endl;
    }
    // system("pause");
    return 0;
}