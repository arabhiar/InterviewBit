#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<vector<int>> ans;

    unordered_map<string, vector<int>> um;
    for (int i = 0; i < A.size(); i++)
    {
        string temp = A[i];
        sort(temp.begin(), temp.end());
        um[temp].push_back(i + 1);
    }
    for (auto it : um)
    {
        ans.push_back(it.second);
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