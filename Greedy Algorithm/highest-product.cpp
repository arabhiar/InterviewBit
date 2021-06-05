#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    int n = A.size();
    if (n < 3)
    {
        return 0;
    }
    sort(A.begin(), A.end());
    return max(A[n - 1] * A[n - 2] * A[n - 3], A[0] * A[1] * A[n - 1]);
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}