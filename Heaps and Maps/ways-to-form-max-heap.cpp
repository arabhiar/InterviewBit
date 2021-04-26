#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int gcdExtended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }

    int x1, y1;
    int gcd = gcdExtended(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;

    return gcd;
}

int modInverse(int b, int m)
{
    int x, y;
    int g = gcdExtended(b, m, &x, &y);

    if (g != 1)
        return -1;

    return (x % m + m) % m;
}

long long int fact(int n)
{
    // return n == 0 || n == 1 ? 1 : n * fact(n - 1);
    return n == 0 || n == 1 ? 1 : ((n % M) * (fact(n - 1) % M)) % M;
}

int main()
{
    int A;
    cin >> A;

    vector<int> nodeCount(A, 1);
    for (int i = A / 2 - 1; i >= 0; i--)
    {
        int leftChild = 2 * i + 1;
        int rightChild = 2 * i + 2;
        int sum = 0;
        if (leftChild < A)
        {
            sum += nodeCount[leftChild];
        }
        if (rightChild < A)
        {
            sum += nodeCount[rightChild];
        }
        nodeCount[i] = sum + 1;
    }
    long long int num = fact(A);
    long long int mul = 1;
    for (auto it : nodeCount)
    {
        mul *= it;
        mul %= M;
    }
    int inv = modInverse(mul, M);
    int ans = (inv * num) % M;

    cout << ans % M;
    cout << endl;

    return 0;
}