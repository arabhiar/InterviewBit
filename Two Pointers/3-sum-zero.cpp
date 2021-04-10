#include <bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<vector<int>> ans;
    sort(A.begin(), A.end());
    int i = 0;

    if (A.size() >= 3)
    {
        while (i < A.size() - 2)
        {
            int l = i + 1;
            int r = A.size() - 1;
            while (l < r)
            {
                ll currSum = (ll)A[i] + (ll)A[l] + (ll)A[r];
                if (currSum == 0)
                {
                    ans.push_back({A[i], A[l], A[r]});
                    int front = A[l];
                    int back = A[r];
                    while (l < r && A[l] == front)
                    {
                        l++;
                    }
                    while (l < r && A[r] == back)
                    {
                        r--;
                    }
                }
                else if (currSum > 0)
                {
                    r--;
                }
                else
                {
                    l++;
                }
            }
            while (A[i] == A[i + 1])
            {
                i++;
            }
            i++;
        }
    }

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << " " << it[2] << endl;
        ;
    }

    return 0;
}