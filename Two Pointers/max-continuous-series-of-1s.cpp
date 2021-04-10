#include<bits/stdc++.h>
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

    int l = 0, r = 0;
    int count_0 = 0;
    int maxLen = INT_MIN;
    int idx = -1;
    while (l < A.size() && r < A.size())
    {
        if (A[r] == 0)
        {
            count_0++;
        }
        if (count_0 > B)
        {
            while (A[l] == 1)
            {
                l++;
            }
            l++;
            count_0--;
        }
        int currLen = r - l + 1;
        if (currLen > maxLen)
        {
            maxLen = currLen;
            idx = l;
        }
        r++;
    }
    vector<int> ans(maxLen);
    for (int i = 0; i < maxLen; i++)
    {
        ans[i] = idx + i;
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << idx << " " << maxLen;
    cout << endl;

    return 0;
}