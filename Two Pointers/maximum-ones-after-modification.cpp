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

    int i = 0;
    int j = 0;
    int count_0 = 0;
    int ans = INT_MIN;
    while (i < A.size() && j < A.size())
    {
        if (A[j] == 0)
        {
            count_0++;
        }
        if (count_0 > B)
        {
            while (A[i] != 0)
            {
                i++;
            }
            i++;
            count_0--;
        }

        ans = max(ans, j - i + 1);

        j++;
    }

    cout << ans;
    cout << endl;

    return 0;
}