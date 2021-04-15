#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &A, vector<vector<int>> &res, vector<int> &track)
{
    if (track.size() == A.size())
    {
        res.push_back(track);
        return;
    }
    for (int i = 0; i < A.size(); i++)
    {
        if (find(track.begin(), track.end(), A[i]) != track.end())
        {
            continue;
        }
        track.push_back(A[i]);
        backtrack(A, res, track);
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
    sort(A.begin(), A.end());
    vector<int> track;
    backtrack(A, res, track);

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