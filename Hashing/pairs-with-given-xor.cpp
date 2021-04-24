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
    int B;
    cin >> B;

    unordered_set<int> s;
    int ans = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (s.find(A[i] ^ B) != s.end())
        {
            ans++;
        }
        s.insert(A[i]);
    }

    cout << ans;
    cout << endl;

    return 0;
}