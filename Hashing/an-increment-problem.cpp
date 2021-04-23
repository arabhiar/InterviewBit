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

    vector<int> ans;
    unordered_map<int, int> um;
    for (int i = 0; i < A.size(); i++)
    {
        ans.push_back(A[i]);
        if (um.find(A[i]) == um.end())
        {
            um[A[i]] = i;
        }
        else
        {
            int idx = um[A[i]];
            int temp = ans[idx];
            ans[idx]++;
            um[ans[idx]] = idx;
            if (find(ans.begin(), ans.end(), temp) != ans.end())
            {
                um[temp] = find(ans.begin(), ans.end(), temp) - ans.begin();
            }
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}