#include<bits/stdc++.h>
using namespace std;

#define M 10003

int main()
{
    string A;
    cin >> A;

    int ans = 0;

    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == 'A' || A[i] == 'E' || A[i] == 'I' || A[i] == 'O' || A[i] == 'U' || A[i] == 'a' || A[i] == 'e' || A[i] == 'i' || A[i] == 'o' || A[i] == 'u')
        {
            int count = A.length() - i;
            count = count % M;
            ans += count;
            ans %= M;
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}