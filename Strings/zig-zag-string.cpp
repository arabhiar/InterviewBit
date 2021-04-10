#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    int B;
    cin >> A;
    cin >> B;

    vector<vector<int>> v(B);

    int idx = 0;

    while (idx < A.length())
    {
        for (int i = 0; i < B; i++)
        {
            if (idx >= A.length())
            {
                break;
            }
            v[i].push_back(idx);
            idx++;
        }
        for (int i = B - 2; i > 0; i--)
        {
            if (idx >= A.length())
            {
                break;
            }
            v[i].push_back(idx);
            idx++;
        }
    }

    string ans = "";
    for (int i = 0; i < B; i++)
    {
        for (auto it : v[i])
        {
            ans += A[it];
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}