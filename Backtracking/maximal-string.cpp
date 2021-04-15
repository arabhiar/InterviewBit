#include <bits/stdc++.h>
using namespace std;

void backtrack(string &res, string &track, int count, int B)
{
    if (count == B)
    {
        res = max(res, track);
        return;
    }
    for (int i = 0; i < track.length() - 1; i++)
    {
        for (int j = i + 1; j < track.length(); j++)
        {
            swap(track[i], track[j]);
            backtrack(res, track, count + 1, B);
            swap(track[i], track[j]);
        }
    }
}

int main()
{
    string A;
    int B;
    cin >> A >> B;

    string res = A;
    string track = A;
    backtrack(res, track, 0, B);

    cout << res << endl;

    return 0;
}