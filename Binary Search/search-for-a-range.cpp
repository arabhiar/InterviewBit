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
    int start = 0;
    int end = n - 1;
    int start_index = INT_MAX;
    vector<int> ans(2);
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] >= B)
        {
            if (A[mid] == B)
            {
                start_index = min(mid, start_index);
            }
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    start = 0;
    end = n - 1;
    int end_index = INT_MIN;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] <= B)
        {
            if (A[mid] == B)
            {
                end_index = max(end_index, mid);
            }
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    if (start_index == INT_MAX)
    {
        start_index = -1;
    }
    if (end_index == INT_MIN)
    {
        end_index = -1;
    }
    ans[0] = start_index;
    ans[1] = end_index;
    cout << start_index << " " << end_index;
    cout << endl;
    return 0;
}