#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &track, vector<int> &A, int idx)
{
    if (find(res.begin(), res.end(), track) == res.end())
        res.push_back(track);

    for (int i = idx; i < A.size(); i++)
    {
        track.push_back(A[i]);
        backtrack(res, track, A, i + 1);
        track.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<vector<int>> res;
    vector<int> track;
    sort(A.begin(), A.end());
    backtrack(res, track, A, 0);

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