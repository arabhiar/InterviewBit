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
    int B;
    cin >> B;

    vector<vector<int>> ans;
    if (A.size() > 3)
    {
        sort(A.begin(), A.end());
        unordered_map<ll, vector<pair<int, int>>> um;
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int currSum = A[i] + A[j];
                um[currSum].push_back({i, j});
            }
        }
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int currSum = A[i] + A[j];
                int req = B - currSum;
                if (um.find(req) != um.end())
                {
                    // found
                    for (auto it : um[req])
                    {
                        if (it.first != i && it.second != j && it.second != i && it.first != j)
                        {
                            vector<int> temp({A[i], A[j], A[it.first], A[it.second]});
                            sort(temp.begin(), temp.end());
                            if (find(ans.begin(), ans.end(), temp) == ans.end())
                            {
                                ans.push_back(temp);
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}