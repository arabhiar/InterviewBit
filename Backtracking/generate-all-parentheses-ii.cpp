#include <bits/stdc++.h>
using namespace std;

bool isValid(string s)
{

    if (s.length() % 2 != 0)
    {
        return false;
    }
    int balance = 0;
    int flag = 1;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            balance++;
        }
        else
        {
            balance--;
        }
        if (balance < 0)
        {
            flag = 0;
            break;
        }
    }
    if (flag == 0)
    {
        return false;
    }
    else
    {
        if (balance == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void backtrack(vector<string> &res, string &track, int A, vector<char> options)
{
    if (track.length() == 2 * A)
    {
        if (isValid(track))
        {
            res.push_back(track);
        }
        return;
    }
    for (auto ch : options)
    {
        track += ch;
        backtrack(res, track, A, options);
        track = track.substr(0, track.length() - 1);
    }
}

int main()
{
    int A;
    cin >> A;

    vector<string> res;
    string track = "";
    vector<char> options({'(', ')'});
    backtrack(res, track, A, options);

    for (auto st : res)
    {
        cout << st << endl;
    }
    cout << endl;

    return 0;
}