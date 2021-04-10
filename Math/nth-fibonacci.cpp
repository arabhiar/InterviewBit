#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

vector<long long int> multiply(vector<long long int> m1, vector<long long int> m2)
{
    vector<long long int> ans(4);
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

vector<long long int> matPower(vector<long long int> arr, int n)
{
    if (n == 1)
    {
        return arr;
    }
    vector<long long int> temp = matPower(arr, n / 2);
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
    int ans = 1;
    if (A > 2)
    {
        vector<long long int> arr = {1, 1, 1, 0};
        arr = matPower(arr, A - 1);
        // cout << arr[0] << "\n";
        ans = arr[0] % M;
    }
    cout << ans;
    cout << endl;
    return 0;
}