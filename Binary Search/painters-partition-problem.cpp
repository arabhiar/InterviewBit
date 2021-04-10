#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define M 10000003

int main()
{
    int A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    vector<int> C(n);
    for (int i = 0; i < n; i++)
    {
        cin >> C[i];
    }

    ll low = *max_element(C.begin(), C.end());
    ll high = accumulate(C.begin(), C.end(), 0);

    while (low <= high)
    {
        ll mid = low + (high - low) / 2;
        ll currSum = 0;
        int paintersReq = 1;
        for (int i = 0; i < n; i++)
        {
            currSum += C[i];
            if (currSum > mid)
            {
                currSum = C[i];
                paintersReq++;
            }
        }
        if (paintersReq <= A)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << ((low % M) * (B % M)) % M;
    cout << endl;
    return 0;
}