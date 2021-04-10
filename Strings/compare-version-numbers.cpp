#include <bits/stdc++.h>
using namespace std;

// 0.1 < 1.1 < 1.2 < 1.13 < 1.13.4

int compare_tokens(string tk1, string tk2)
{
    long double t1 = 0, t2 = 0;
    if (tk1.length())
    {
        t1 = stold(tk1);
    }
    if (tk2.length())
    {
        t2 = stold(tk2);
    }
    int result = t1 == t2 ? 0 : t1 > t2 ? 1 : -1;
    return result;
}

int main()
{
    string A;
    string B;
    cin >> A;
    cin >> B;

    istringstream stream1(A);
    istringstream stream2(B);
    string tk1;
    string tk2;
    int ans = 0;

    while(stream1 || stream2)
    {
        tk1 = "";
        tk2 = "";
        if (stream1)
        {
            getline(stream1, tk1, '.');
        }
        if (stream2)
        {
            getline(stream2, tk2, '.');
        }
        int result = compare_tokens(tk1, tk2);
        if (result != 0)
        {
            ans = result;
            break;
        }
    }

    cout << ans;
    cout << endl;
    return 0;
}