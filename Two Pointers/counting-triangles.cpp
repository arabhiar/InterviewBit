#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    sort(A.begin(), A.end());
    ll count = 0;
    int i = A.size() - 1;
    while (i > 1)
    {
        int l = 0;
        int r = i - 1;
        while (l < r)
        {
            if (A[l] + A[r] > A[i])
            {
                count += (r - l);
                count %= M;
                r--;
            }
            else
            {
                l++;
            }
        }
        i--;
    }

    cout << count;
    cout << endl;

    return 0;
}