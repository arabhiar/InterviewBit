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

    int l = 0, r = A.size() - 1;
    int maxArea = INT_MIN;
    if (A.size() > 1)
    {
        while (l < r)
        {
            int minHeight = min(A[l], A[r]);
            int currArea = minHeight * (r - l);
            maxArea = max(maxArea, currArea);
            if (minHeight == A[l])
            {
                l++;
            }
            else
            {
                r--;
            }
        }
    }
    else
    {
        maxArea = 0;
    }

    cout << maxArea;
    cout << endl;

    return 0;
}