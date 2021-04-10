#include <bits/stdc++.h>
using namespace std;

bool is_palindrome(string s, int l, int r)
{
    while (l < r)
    {
        if (s[l] != s[r])
        {
            return false;
        }
        l++;
        r--;
    }
    return true;
}

bool is_possible(string s)
{
    for (int i = 0; i < s.length() / 2; i++)
    {
        if (s[i] != s[s.length() - i - 1])
        {
            return is_palindrome(s, i + 1, s.length() - i - 1) || is_palindrome(s, i, s.length() - i - 2);
        }
    }
    return true;
}

int main()
{
    string A;
    cin >> A;

    int ans = 0;
    if (is_possible(A))
    {
        ans = 1;
    }

    cout << ans;
    cout << endl;

    return 0;
}