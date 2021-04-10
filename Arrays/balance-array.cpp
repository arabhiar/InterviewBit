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
        vector<int> oddLeftSum(n, 0);
        vector<int> evenLeftSum(n, 0);
        evenLeftSum[0] = A[0];
        evenLeftSum[1] = A[0];
        oddLeftSum[0] = 0;
        oddLeftSum[1] = A[1];
        for (int i = 2; i < n; i++)
        {
            if (i % 2 == 0)
            {
                evenLeftSum[i] = evenLeftSum[i - 1] + A[i];
                oddLeftSum[i] = oddLeftSum[i - 1];
            }
            else
            {
                oddLeftSum[i] = oddLeftSum[i - 1] + A[i];
                evenLeftSum[i] = evenLeftSum[i - 1];
            }
        }
        int ans = 0;
        int oddIndexSum = 0, evenIndexSum = 0;
        for (int i = 0; i < n; i++)
        {
            if (i - 1 >= 0)
            {
                evenIndexSum += evenLeftSum[i - 1];
                oddIndexSum += oddLeftSum[i - 1];
            }
            evenIndexSum += (oddLeftSum[n - 1] - oddLeftSum[i]);
            oddIndexSum += (evenLeftSum[n - 1] - evenLeftSum[i]);
            if (evenIndexSum == oddIndexSum)
            {
                ans++;
            }
            oddIndexSum = 0;
            evenIndexSum = 0;
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}