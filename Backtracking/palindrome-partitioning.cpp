#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp;
}

void backtrack(vector<vector<string>> &res, vector<string> &track, int idx, string A)
{
    if (idx == A.length())
    {
        res.push_back(track);
        return;
    }
    for (int i = idx, j = 0; i < A.length(); i++, j++)
    {
        string curr = A.substr(idx, j + 1);
        if (!isPalindrome(curr))
        {
            continue;
        }
        track.push_back(curr);
        backtrack(res, track, j + idx + 1, A);
        track.pop_back();
    }
}

int main()
{
    string A;
    cin >> A;

    vector<vector<string>> res;
    vector<string> track;
    backtrack(res, track, 0, A);

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