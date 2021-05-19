#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    vector<int> lis(A.size(), 1), lds(A.size(), 1);
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (A[j] < A[i])
            {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }
    for (int i = A.size() - 1; i >= 0; i--)
    {
        for (int j = A.size() - 1; j > i; j--)
        {
            if (A[j] < A[i])
            {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }
    for (int i = 0; i < A.size(); i++)
    {
        ans = max(ans, lis[i] + lds[i] - 1);
    }
    return ans;
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