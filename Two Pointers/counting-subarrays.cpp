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

    vector<int> preSum(A.size() + 1);
    preSum[0] = 0;
    preSum[1] = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        preSum[i + 1] = preSum[i] + A[i];
    }
    int i = 0;
    int j = i + 1;
    int ans = 0;
    while (i < preSum.size() && j < preSum.size())
    {
        int currDiff = preSum[j] - preSum[i];
        if (currDiff >= B)
        {
            i++;
            if (i == j)
            {
                j++;
            }
        }
        else
        {
            ans += (j - i);
            j++;
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}