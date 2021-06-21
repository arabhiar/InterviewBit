#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    unordered_set<int> s;
    for (int i = 0; i < A.size(); i++)
    {
        s.insert(A[i]);
    }
    int ans = 0;
    for (auto it : A)
    {
        if (s.find(it - 1) == s.end())
        {
            int j = it;
            while (s.find(j) != s.end())
                j++;
            ans = max(ans, j - it);
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    
    cout << helper(A);

    cout << endl;
    return 0;
}