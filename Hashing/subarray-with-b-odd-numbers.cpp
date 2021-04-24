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

    int oddCount = 0;
    unordered_map<int, int> um;
    for (int i = 0; i < A.size(); i++)
    {
        if (A[i] % 2 != 0)
        {
            oddCount++;
            um[oddCount] = i;
        }
    }
    long long int ans = 0;
    if (B == 0)
    {
        int count = 1;
        while (um.find(count) != um.end())
        {
            if (count == 1)
            {
                if (um[count] > 0)
                {
                    ans += powl(2, um[count]) - 1;
                }
            }
            else
            {
                if (um[count] - um[count - 1] - 1 > 0)
                {
                    ans += powl(2, um[count] - um[count - 1] - 1) - 1;
                }
            }
            count++;
        }
        if (um.find(count - 1) != um.end())
        {
            if (A.size() - um[count - 1] - 1 > 0)
            {
                ans += powl(2, A.size() - um[count - 1] - 1) - 1;
            }
        }
        else
        {
            ans += powl(2, A.size()) - 1;
        }
    }
    if (um.size() >= B)
    {
        int count = B;
        long long int left, right;
        while (um.find(count) != um.end())
        {
            left = count == B ? um[count - (B - 1)] + 1 : um[count - (B - 1)] - um[count - B];
            right = um.find(count + 1) == um.end() ? A.size() - um[count] : um[count + 1] - um[count];
            ans += left > 0 && right > 0 ? (left * right) : 0;
            count++;
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}