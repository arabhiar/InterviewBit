#include <bits/stdc++.h>
using namespace std;

int uniquePaths(int A, int B)
{
    if (A == 1 || B == 1)
    {
        return 1;
    }
    return uniquePaths(A - 1, B) + uniquePaths(A, B - 1);
}

int main()
{
    int A, B;
    cin >> A >> B;
    int ans = uniquePaths(A, B);
    cout << ans;
    cout << "\n";
    return 0;
}