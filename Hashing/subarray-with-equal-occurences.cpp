#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B, C;
    cin >> B >> C;

    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        int countB = 0, countC = 0;
        for (int j = i; j < A.size(); j++)
        {
            if (A[j] == B)
            {
                countB++;
            }
            else if (A[j] == C)
            {
                countC++;
            }
            if (countB == countC)
            {
                ans++;
            }
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}