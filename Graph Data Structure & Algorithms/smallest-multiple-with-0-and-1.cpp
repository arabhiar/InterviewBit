#include <bits/stdc++.h>
using namespace std;

string helper(int A)
{
    if (A == 1)
        return "1";
    vector<int> parent(A, -1);
    vector<int> state(A, -1);
    queue<int> q;
    q.push(1);
    parent[1] = -2;
    state[1] = 1;
    bool found = false;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        if (curr == 0)
        {
            found = true;
            break;
        }
        for (int i = 0; i < 2; i++)
        {
            int rem = (curr * 10 + i) % A;
            if (parent[rem] == -1)
            {
                parent[rem] = curr;
                state[rem] = i;
                q.push(rem);
            }
        }
    }
    if (found)
    {
        string ans;
        int idx = 0;
        while (parent[idx] != -2)
        {
            int nextIdx = parent[idx];
            ans += '0' + state[idx];
            idx = nextIdx;
        }
        ans += "1";
        reverse(ans.begin(), ans.end());
        return ans;

    }
    else
    {
        return "-1";
    }
}

int main()
{
    int A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}