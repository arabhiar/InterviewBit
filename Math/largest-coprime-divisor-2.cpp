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
    while (gcd(A, B) != 1)
    {
        A = A / gcd(A, B);
    }
    cout << A;
    cout << endl;
    return 0;
}