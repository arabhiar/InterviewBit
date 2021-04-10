#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, m, n;
    cin >> l >> m >> n;
    vector<int> A(l);
    vector<int> B(m);
    vector<int> C(n);
    for (int i = 0; i < l; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];
    for (int i = 0; i < n; i++)
        cin >> C[i];
    
    int i = 0, j = 0, k = 0;
    int ans = INT_MAX;
    while (i < l && j < m && k < n)
    {
        int v1 = abs(A[i] - B[j]);
        int v2 = abs(B[j] - C[k]);
        int v3 = abs(C[k] - A[i]);
        int temp = max(max(v1, v2), v3);
        ans = min(ans, temp);
        if (temp == v1)
        {
            if (A[i] < B[j])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
        else if (temp == v2)
        {
            if (B[j] < C[k])
            {
                j++;
            }
            else
            {
                k++;
            }
        }
        else
        {
            if (C[k] < A[i])
            {
                k++;
            }
            else
            {
                i++;
            }
        }
    }
    
    cout << ans;
    cout << endl;

    return 0;
}