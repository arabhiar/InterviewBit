#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i= 0; i < n; i++)
    {
        cin >> A[i];
    }

    int ans = -1;
    unordered_map<int, int> um;
    for (auto it : A)
    {
        um[it]++;
    }
    for (auto it : A)
    {
        if (um[it] > 1)
        {
            ans = it;
            break;
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}