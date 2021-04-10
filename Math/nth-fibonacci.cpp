#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

vector<long> multiply(vector<long> m1, vector<long> m2)
{
    vector<long> ans(4);
    for (int i = 0; i < 4; i++)
    {
        m1[i] %= M;
        m2[i] %= M;
    }
    ans[0] = ((m2[0] * m1[0]) % M + (m2[2] * m1[1]) % M) % M;
    ans[1] = ((m2[1] * m1[0]) % M + (m2[3] * m1[1]) % M) % M;
    ans[2] = ((m2[0] * m1[2]) % M + (m2[2] * m1[3]) % M) % M;
    ans[3] = ((m2[1] * m1[2]) % M + (m2[3] * m1[3]) % M) % M;
    return ans;
}

vector<long> matPower(vector<long> arr, int n)
{
    if (n == 1)
    {
        return arr;
    }
    vector<long> temp = matPower(arr, n / 2);
    if (n % 2 == 0)
    {
        return multiply(temp, temp);
    }
    return multiply(multiply(temp, temp), arr);
}

int main()
{
    int A;
    cin >> A;
    long s;
    s = LONG_MAX;
    cout << s << "\n";
    printf("The size of char in bytes is: %llu.", sizeof(char));
    printf("\nThe size of short in bytes is: %llu.", sizeof(short));
    printf("\nThe size of int in bytes is: %llu.", sizeof(int));
    printf("\nThe size of long in bytes is: %llu.", sizeof(long));
    printf("\nThe size of long long in bytes is: %llu.", sizeof(long long));
    printf("\nThe size of float in bytes is: %llu.", sizeof(float));
    printf("\nThe size of double in bytes is: %llu.", sizeof(double));
    printf("\nThe size of long double in bytes is: %llu.", sizeof(long double));
    int ans = 1;
    if (A > 2)
    {
        vector<long> arr = {1, 1, 1, 0};
        arr = matPower(arr, A - 1);
        // cout << arr[0] << "\n";
        ans = arr[0] % M;
    }
    cout << ans;
    cout << endl;
    return 0;
}