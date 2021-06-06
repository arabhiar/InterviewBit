#include <bits/stdc++.h>
using namespace std;

// kind of bucket sort
vector<int> helper(vector<int> &A, int B)
{
    int n = A.size();
    vector<int> ans(n);
    vector<int> map(n + 1);
    for (int i = 0; i < n; i++)
    {
        map[A[i]] = i;
    }
    if (n == 0)
    {
        return ans;
    }
    ans = A;
    int end = n;
    int startIdx = 0, idx;
    while (B && startIdx < n)
    {
        idx = map[end];
        if (ans[startIdx] < ans[idx])
        {
            swap(ans[idx], ans[startIdx]);
            swap(map[ans[idx]], map[ans[startIdx]]);
            B--;
        }
        end--;
        startIdx++;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int B;
    cin >> B;

    auto ans = helper(A, B);

    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}