#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &res, int &track, int n)
{
    if (n == 0)
    {
        res.push_back(track);
        return;
    }
    backtrack(res, track, n - 1);
    track ^= (1 << (n - 1));
    backtrack(res, track, n - 1);
}

int main()
{
    int A;
    cin >> A;

    vector<int> res;
    int track = 0;
    backtrack(res, track, A);

    for (auto it : res)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}