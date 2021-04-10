#include <bits/stdc++.h>
using namespace std;

long long int gettingWood(vector<int> v, int height)
{
    long long int sum = 0;
    for (auto it : v)
    {
        if (height < it)
        {
            sum += (it - height);
        }
    }
    return sum;
}

int maxHeight(vector<int> v, int low, int high, int target)
{
    if (low <= high)
    {
        long long int currHeight = (long long int)((low + high) / 2);
        long long int currWood = gettingWood(v, currHeight);
        if (currWood == target)
        {
            return currHeight;
        }
        if (currWood > target && (currHeight == high || gettingWood(v, currHeight + 1) < target))
        {
            return currHeight;
        }
        if (currWood < target)
        {
            return maxHeight(v, low, currHeight - 1, target);
        }
        return maxHeight(v, currHeight + 1, high, target);
    }
    return -1;
}

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
    int ans = maxHeight(A, 0, *max_element(A.begin(), A.end()), B);
    cout << ans;
    cout << endl;
    return 0;
}