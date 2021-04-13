#include <bits/stdc++.h>
using namespace std;

void backtract(vector<string> &res, string &track, string A, int idx, unordered_map<int, vector<char>> &um)
{
    if (track.length() == A.length())
    {
        res.push_back(track);
        return;
    }
    for (int i = 0; i < um[A[idx] - '0'].size(); i++)
    {
        track += um[A[idx] - '0'][i];
        backtract(res, track, A, idx + 1, um);
        track.resize(track.length() - 1);
    }
}

int main()
{
    string A;
    cin >> A;

    unordered_map<int, vector<char>> um;
    um[0] = {'0'};
    um[1] = {'1'};
    um[2] = {'a', 'b', 'c'};
    um[3] = {'d', 'e', 'f'};
    um[4] = {'g', 'h', 'i'};
    um[5] = {'j', 'k', 'l'};
    um[6] = {'m', 'n', 'o'};
    um[7] = {'p', 'q', 'r', 's'};
    um[8] = {'t', 'u', 'v'};
    um[9] = {'w', 'x', 'y', 'z'};
    vector<string> res;
    string track = "";
    backtract(res, track, A, 0, um);

    for (auto it : res)
    {
        cout << it << "\n";
    }

    return 0;
}