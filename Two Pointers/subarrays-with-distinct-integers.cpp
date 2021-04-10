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

    vector<int> m(A.size() + 1);
    int res = 0;
    for (auto i = 0, j = 0, prefix = 0, cnt = 0; i < A.size(); ++i)
    {
        if (m[A[i]]++ == 0)
            ++cnt;
        if (cnt > B)
            --m[A[j++]], --cnt, prefix = 0;
        while (m[A[j]] > 1)
            ++prefix, --m[A[j++]];
        if (cnt == B)
            res += prefix + 1;
    }

    cout << res;
    cout << endl;

    return 0;
}