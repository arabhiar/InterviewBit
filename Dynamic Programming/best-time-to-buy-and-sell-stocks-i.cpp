#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    int n = A.size();
    if (n == 0)
        return 0;
    vector<int> maxArr(n);
    maxArr[n - 1] = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxArr[i] = max(maxArr[i + 1], A[i]);
    }
    int maxProfit = 0;
    for (int i = 0; i < n - 1; i++)
    {
        maxProfit = max(maxProfit, maxArr[i + 1] - A[i]);
    }
    return maxProfit;
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