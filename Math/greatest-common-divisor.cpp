#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
    {
        return b;
    }
    return gcd(b % a, a);
}

int main()
{
    int A, B;
    cin >> A >> B;
    cout << gcd(A, B);
    cout << endl;
    return 0;
}