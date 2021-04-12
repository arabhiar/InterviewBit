#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &A, int idx, vector<vector<int>> &res, vector<int> &track)
{
    res.push_back(track);
    for (int i = idx; i < A.size(); i++)
    {
        track.push_back(A[i]);
        backtrack(A, i + 1, res, track);
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
    backtrack(A, 0, res, track);

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