#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

// int calcDiff(int a, int b)
// {
//     int count = 0;
//     int temp = a ^ b;
//     while (temp)
//     {
//         temp = (temp & (temp - 1));
//         count++;
//     }
//     return count;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> A(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> A[i];
//     }

//     long long int ans = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             ans += calcDiff(A[i], A[j]);
//             ans %= M;
//         }
//     }

//     cout << ans;
//     cout << endl;

//     return 0;
// }

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    long long int ans = 0;
    
    for (int i = 0; i < 32; i++)
    {
        int temp = 1 << i;
        long long int set_count = 0;
        long long int unset_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] & temp)
            {
                set_count++;
            }
        }
        unset_count = n - set_count;
        ans += set_count * unset_count * 2;
        ans %= M;
    }

    cout << ans;
    cout << endl;

    return 0;
}