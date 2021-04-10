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

    sort(A.begin(), A.end());
    long long int ans, minDiff = INT_MAX;
    int i = 0;
    while (i < A.size() - 2)
    {
        int l = i + 1;
        int r = A.size() - 1;
        while (l < r)
        {
            long long int currSum = A[i] + A[l] + A[r];
            long long int currDiff = abs(currSum - B);

            if (currDiff < minDiff)
            {
                minDiff = currDiff;
                ans = currSum;
            }

            if (currSum < B)
            {
                l++;
            }
            else
            {
                r--;
            }
        }
        i++;
    }

    cout << ans;
    cout << endl;

    return 0;
}