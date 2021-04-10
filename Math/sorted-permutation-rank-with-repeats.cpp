#include <bits/stdc++.h>
using namespace std;

long long int M = 1000003;

long long int modFact(long long int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    return ((n % M) * (modFact(n - 1) % M)) % M;
}

int modInverse(int a, int m)
{
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1)
    {
        // q is quotient
        int q = a / m;
        int t = m;

        // m is remainder now, process same as
        // Euclid's algo
        m = a % m, a = t;
        t = y;

        // Update y and x
        y = x - q * y;
        x = t;
    }

    // Make x positive
    if (x < 0)
        x += m0;

    return x;
}

int findRankUtil(string A, unordered_map<char, int> &freq)
{
    if (A.length() == 1)
    {
        return 1;
    }
    // int count = 0;
    long long int nume = modFact(A.length() - 1);
    long long int res = 0;
    for (auto item1 : freq)
    {
        if (item1.first < A[0] && item1.second > 0)
        {
            long long int deno = 1;
            for (auto item2 : freq)
            {
                int count;
                if (item1.first == item2.first)
                {
                    count = freq[item2.first] - 1;
                }
                else
                {
                    count = freq[item2.first];
                }
                long long int temp = modFact(count);
                deno *= temp;
                deno %= M;
            }
            // long long int temp1 = modInverse(deno, M);
            // long long int temp2 = (nume % M) * (modInverse(deno, M) % M);
            // long long int temp3 = ((nume % M) * (modInverse(deno, M) % M)) % M;
            res += ((nume % M) * (modInverse(deno, M) % M)) % M;
        }
    }
    // int temp = ((nume % M) * (deno % M)) % M;
    // int res = 0;
    // res += (count * temp) % M;
    freq[A[0]]--;
    res += findRankUtil(A.substr(1), freq) % M;
    return res % M;
}

int findRank(string A)
{
    unordered_map<char, int> freq;
    for (auto c : A)
    {
        freq[c]++;
    }
    return findRankUtil(A, freq);
}

int main()
{
    string A;
    cin >> A;
    cout << findRank(A);
    cout << endl;
    return 0;
}