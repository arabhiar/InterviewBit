#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, int idx, int n, int k, vector<int> &track)
{
    if (track.size() == k)
    {
        res.push_back(track);
        return;
    }
    for (int i = idx; i < n; i++)
    {
        track.push_back(i + 1);
        backtrack(res, i + 1, n, k, track);
        track.pop_back();
    }
}

int main()
{
    int A, B;
    cin >> A >> B;

    vector<vector<int>> res;
    vector<int> track;
    backtrack(res, 0, A, B, track);

    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}