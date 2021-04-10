#include <bits/stdc++.h>
using namespace std;

#define M 1000003

long long int modFact(long long int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return ((modFact(n - 1) % M) * (n % M)) % M;
}

long long int findRank(string s)
{
    if (s.length() == 1)
    {
        return 1;
    }
    int curr = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] < s[0])
        {
            curr++;
        }
    }
    long long int ans = 0;
    ans += (modFact(s.length() - 1) * curr) % M;
    ans += findRank(s.substr(1)) % M;
    return ans % M;
}

int main()
{
    string A;
    cin >> A;
    cout << findRank(A);
    cout << endl;
    return 0;
}