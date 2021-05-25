#include <bits/stdc++.h>
using namespace std;

long long int M = 1e9 + 7;

// https://www.geeksforgeeks.org/ways-color-3n-board-using-4-colors/
int helper(int A)
{
    long long int color_2 = 12, color_3 = 24, ans;
    for (int i = 2; i <= A; i++)
    {
        long long int cache1 = color_2, cache2 = color_3;
        color_3 = (10 * cache1 + 11 * cache2) % M;
        color_2 = (7 * cache1 + 5 * cache2) % M;
    }
    ans = (color_2 + color_3) % M;
    return (int)ans;
}

int main()
{
    int A;
    cin >> A;

    cout << helper(A);

    cout << endl;
    return 0;
}
