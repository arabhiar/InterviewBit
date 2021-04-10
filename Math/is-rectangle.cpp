#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A, B, C, D;
        cin >> A >> B >> C >> D;
        unordered_map<int, int> um;
        um[A]++;
        um[B]++;
        um[C]++;
        um[D]++;
        int ans = 0;
        if (um.size() == 2 && um[A] == 2 && um[B] == 2 && um[C] == 2 && um[D] == 2)
        {
            ans = 1;
        }
        cout << ans;
        cout << endl;
    }
    return 0;
}