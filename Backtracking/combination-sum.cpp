#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &res, vector<int> &A, vector<int> &track, int B, int currSum, int idx)
{
    if (currSum == B)
    {
        res.push_back(track);
        return;
    }
    for (int i = idx; i < A.size(); i++)
    {
        if (currSum + A[i] > B)
        {
            continue;
        }
        track.push_back(A[i]);
        backtrack(res, A, track, B, currSum + A[i], i);
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
    int B;
    cin >> B;

    set<int> s;
    for (int i = 0; i < A.size(); i++)
    {
        s.insert(A[i]);
    }
    vector<int> temp;
    for (auto it : s)
    {
        temp.push_back(it);
    }
    sort(temp.begin(), temp.end());
    vector<vector<int>> res;
    vector<int> track;
    backtrack(res, temp, track, B, 0, 0);

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