#include <bits/stdc++.h>
using namespace std;

// https://afteracademy.com/blog/distribute-candy-problem
int helper(vector<int> A)
{
    vector<int> left2right(A.size());
    vector<int> right2left(A.size());
    left2right[0] = 1;
    right2left[A.size() - 1] = 1;
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] > A[i - 1])
        {
            left2right[i] = left2right[i - 1] + 1;
        }
        else
        {
            left2right[i] = 1;
        }
    }
    for (int i = A.size() - 2; i >= 0; i--)
    {
        if (A[i] > A[i + 1])
        {
            right2left[i] = right2left[i + 1] + 1;
        }
        else
        {
            right2left[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        ans += max(left2right[i], right2left[i]);
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