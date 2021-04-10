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
    int B;
    cin >> B;
    int start = 0;
    int end = n - 1;
    int ans = -1;
    while (start <= end)
    {

        int mid = start + (end - start) / 2;
        // cout << mid << "\n";
        if (A[mid] == B)
        {
            ans = mid;
            break;
        }
        if (A[mid - 1] < B && A[mid] > B)
        {
            ans = mid;
            break;
        }
        if (A[mid + 1] > B && A[mid] < B)
        {
            ans = mid + 1;
            break;
        }
        if (A[mid] < B)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (ans == -1 && A[0] > B)
    {
        ans = 0;
    }
    if (ans == -1 && B > A[n - 1])
    {
        ans = n;
    }
    cout << ans;
    cout << endl;
    return 0;
}