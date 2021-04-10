#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        int idx = A[i] % n;
        A[i] = (A[idx] % n) * n + A[i];
    }
    for (int i = 0; i < n; i++)
    {
        A[i] = A[i] / n;
    }
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}