#include <bits/stdc++.h>
using namespace std;

int M = 1e7+3;

int helper(string A)
{
    int l = A.length();
    vector<int> pos;
    for (int i = 0; i < l; i++)
    {
        if (A[i] == 'x')
            pos.push_back(i);
    }
    if (pos.size() == l || pos.size() == 0)
        return 0;
    int midIdx = pos.size() / 2;
    int ans = 0;
    int leftSeated = 1;
    for (int i = 0; i < midIdx; i++)
    {
        ans += pos[midIdx] - pos[i] - leftSeated;
        ans %= M;
        leftSeated++;
    }
    int rightSeated = 1;
    for (int i = midIdx + 1; i < pos.size(); i++)
    {
        ans += pos[i] - pos[midIdx] - rightSeated;
        ans %= M;
        rightSeated++;
    }
    return ans;
}

int main()
{
    string A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}