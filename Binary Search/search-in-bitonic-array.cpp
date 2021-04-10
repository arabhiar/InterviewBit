#include <bits/stdc++.h>
using namespace std;

int ascBSearch(vector<int> v, int left, int right, int target)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        if (v[mid] > target)
        {
            return ascBSearch(v, left, mid - 1, target);
        }
        return ascBSearch(v, mid + 1, right, target);
    }
    return -1;
}

int descBSearch(vector<int> v, int left, int right, int target)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        if (v[mid] == target)
        {
            return mid;
        }
        if (v[mid] > target)
        {
            return descBSearch(v, mid + 1, right, target);
        }
        return descBSearch(v, left, mid - 1, target);
    }
    return -1;
}

int bitonicBSearch(vector<int> v, int left, int right, int target)
{
    if (right >= left)
    {
        int mid = (left + right) / 2;
        bool maxOnRight = false;
        if (v[mid + 1] > v[mid])
        {
            maxOnRight = true;
        }
        if (v[mid] == target)
        {
            return mid;
        }
        if (v[mid] < target && !maxOnRight)
        {
            return bitonicBSearch(v, left, mid - 1, target);
        }
        if (v[mid] < target && maxOnRight)
        {
            return bitonicBSearch(v, mid + 1, right, target);
        }
        int idx = ascBSearch(v, left, mid - 1, target);
        if (idx == -1)
        {
            return descBSearch(v, mid + 1, right, target);
        }
        return idx;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B;
    cin >> B;
    cout << bitonicBSearch(A, 0, A.size() - 1, B);
    return 0;
}