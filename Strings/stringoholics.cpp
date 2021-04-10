#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define ll long long int

int minNoOfRotation(string s)
{
    string temp = s + s;
    return temp.find(s, 1);
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    long long int ans = 1;
    vector<long long int> lcm_arr;

    // for (auto s : A)
    // {
    //     int min_ = minNoOfRotation(s);
    //     for (long long int i = 1; i <= 2 * min_ + 1; i++)
    //     {
    //         if ((i * (i + 1) / 2) % min_ == 0)
    //         {
    //             lcm_arr.push_back(i);
    //             break;
    //         }
    //     }
    // }

    lcm_arr.push_back(6);
    lcm_arr.push_back(8);
    lcm_arr.push_back(10);
    lcm_arr.push_back(12);

    for (ll i = 0; i < lcm_arr.size(); i++)
    {
        for (ll j = i + 1; j < lcm_arr.size() && lcm_arr[i] != 1; j++)
        {
            lcm_arr[j] = lcm_arr[j] / __gcd(lcm_arr[j], lcm_arr[i]);
        }
        ans = 1ll * (ans % M * (lcm_arr[i]) % M) % M;
    }
    ans = ans % M;
    cout << ans;
    cout << endl;

    return 0;
}