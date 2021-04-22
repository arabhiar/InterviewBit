#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B;
    cin >> A >> B;

    string ans = "";
    long long int num = A;
    long long int den = B;
    int sign = (num >= 0) ^ (den >= 0) ? 0 : 1;
    if (sign == 0 && num != 0)
    {
        ans += '-';
    }
    num = abs(num);
    den = abs(den);
    ans += to_string(num / den);
    if (num % den != 0)
    {
        ans += ".";
        unordered_map<long long int, long long int> um;
        bool repeating = false;
        int startIndex = -1;
        long long int rem = num % den;
        while (rem != 0)
        {
            if (um.find(rem) != um.end())
            {
                startIndex = um[rem];
                repeating = true;
                break;
            }
            else
            {
                um[rem] = ans.length();
            }
            rem = rem * 10;
            ans += to_string(rem / den);
            rem %= den;
        }
        if (repeating)
        {
            string part1 = ans.substr(0, startIndex);
            string part2 = ans.substr(startIndex);
            ans = part1 + '(' + part2 + ')';
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}