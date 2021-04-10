#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> A(m);
    vector<int> B(n);
    for (int i = 0; i < m; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    A.resize(m + n);

    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0)
    {
        if (A[i] < B[j])
        {
            A[i + j + 1] = B[j];
            j--;
        }
        else
        {
            A[i + j + 1] = A[i];
            i--;
        }
    }
    while (j >= 0)
    {
        A[j] = B[j];
        j--;
    }
    for (auto it : A)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}