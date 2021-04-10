#include <bits/stdc++.h>
using namespace std;

int findInArr(vector<int> v, int left, int right, int target)
{
    if (left <= right)
    {
        int mid = (left + right) / 2;
        if (v[mid] == target && v[mid + 1] > v[mid])
        {
            return mid;
        }
        if (v[mid] <= target && (mid == v.size() - 1 || v[mid + 1] > target))
        {
            return mid;
        }
        if (v[mid] > target)
        {
            return findInArr(v, left, mid - 1, target);
        }
        return findInArr(v, mid + 1, right, target);
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
    int ans = findInArr(A, 0, A.size() - 1, B);
    cout << ans + 1;
    cout << endl;
    return 0;
}