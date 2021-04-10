#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    int count = 0;
    int ans = 0;
    for (auto c : A)
    {
        if (c == '(')
        {
            count++;
        }
        else
        {
            if (count <= 0)
            {
                ans++;
            }
            else
            {
                count--;
            }
        }
    }
    ans += count;
    cout << ans;
    cout << endl;
    return 0;
}