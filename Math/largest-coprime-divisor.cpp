#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> primeFactor(int n)
{
    unordered_map<int, int> res;
    while (n % 2 == 0)
    {
        res[2]++;
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            res[i]++;
            n /= i;
        }
    }
    if (n > 2)
    {
        res[n]++;
    }
    return res;
}

int main()
{
    int A, B;
    cin >> A >> B;
    unordered_map<int, int> primeFactorA = primeFactor(A);
    unordered_map<int, int> primeFactorB = primeFactor(B);
    int ans = 1;
    for (auto item : primeFactorA)
    {
        if (primeFactorB.find(item.first) == primeFactorB.end())
        {
            ans *= (pow(item.first, item.second));
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}