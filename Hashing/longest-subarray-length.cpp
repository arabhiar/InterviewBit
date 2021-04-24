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

    unordered_map<int, int> um;
    int sum = 0, ans = INT_MIN;
    for (int i = 0; i < A.size(); i++)
    {
        sum += A[i] == 0 ? -1 : 1;
        if (sum == 1)
        {
            ans = i + 1;
        }
        else if (um.find(sum) == um.end())
        {
            um[sum] = i;
        }
        if (um.find(sum - 1) != um.end())
        {
            ans = max(ans, i - um[sum - 1]);
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}