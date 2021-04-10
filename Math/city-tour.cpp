#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int modPower(long long x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    if (x == 0)
        return 0;

    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

long long int modFact(long long int n)
{
    return n == 0 || n == 1 ? 1 : ((n % M) * (modFact(n - 1) % M)) % M;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        int q = a / m;
        int t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0)
        x += m0;

    return x;
}

int main()
{
    int A;
    cin >> A;
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    long long int ans;
    if (B.size() > 0)
    {
        sort(B.begin(), B.end());
        vector<int> deno;
        deno.push_back(B[0] - 1);
        for (int i = 1; i < B.size(); i++)
        {
            int t = B[i] - B[i - 1] - 1;
            t == 0 ? deno.push_back(1) : deno.push_back(t);
        }
        deno.push_back(A - B[B.size() - 1]);
        long long int down = 1;
        for (int i = 0; i < deno.size(); i++)
        {
            down *= modFact(deno[i]);
            down = down % M;
        }
        long long int up = 1;
        for (int i = 1; i < deno.size() - 1; i++)
        {
            up *= modPower(2, deno[i] - 1, M);
            up = up % M;
        }
        long long int temp = modFact(A - B.size());
        up = (temp * up) % M;
        ans = ((up % M) * (modInverse(down, M) % M)) % M;
    }
    else
    {
        ans = modFact(A);
    }
    cout << ans;
    cout << "\n";
    return 0;
}