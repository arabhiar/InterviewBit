#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    int i = 0, j = A.size() - 1;
    int ans = 0;
    while (i < j)
    {
        if (A[i] > A[j])
        {
            ans += A[i];
            i++;
        }
        else
        {
            ans += A[j];
            j--;
        }
        if (A[i] > A[j])
        {
            i++;
        }
        else
        {
            j--;
        }
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