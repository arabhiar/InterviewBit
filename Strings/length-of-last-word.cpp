#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    getline(cin, A);
    int l = A.length();
    int ans = 0;
    if (l > 0)
    {
        
        int i = l - 1;
        for (; A[i] == ' '; i--){}
        l = i + 1;
        while (A[i] != ' ' && i >= 0)
        {
            i--;
        }
        ans = l - (i + 1);
    }
    cout << ans;
    cout << endl;
    return 0;
}