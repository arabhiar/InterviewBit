#include <bits/stdc++.h>
using namespace std;

int power(int x, int n, int d)
{
    if (x == 0)
    {
        return 0;
    }
    if (n == 0)
    {
        return 1;
    }
    if (n % 2 == 0)
    {
        long long int t = power(x, n / 2, d) % d;
        return (t * t) % d;
    }
    long long int t = power(x, (n - 1) / 2, d) % d;
    int temp = ((((((x % d) + d) % d) * t) % d) * t) % d;
    return temp;
}

int main()
{
    int x, n, d;
    cin >> x >> n >> d;
    cout << power(x, n, d);
    cout << endl;
    return 0;
}