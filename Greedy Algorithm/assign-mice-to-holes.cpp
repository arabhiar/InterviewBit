#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, vector<int> B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int maxDiff = 0;
    for (int i = 0; i < A.size(); i++)
    {
        maxDiff = max(maxDiff, abs(A[i] - B[i]));
    }
    return maxDiff;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << helper(A, B);

    cout << endl;
    return 0;
}