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

    int ans = INT_MIN;
    if (n < 3)
    {
        ans = 0;
    }
    for (int i = 1; i < n - 1; i++)
    {
        int left = 0, right = 0;
        for (int j = i - 1; j >= 0; j--)
        {
            if (A[j] > A[i])
            {
                left = j;
                break;
            }
        }
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] > A[i])
            {
                right = j;
                break;
            }
        }
        ans = max(ans, left * right);
    }

    cout << ans;
    cout << endl;

    return 0;
}