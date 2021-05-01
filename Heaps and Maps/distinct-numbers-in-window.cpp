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

    unordered_map<int, int> um;
    vector<int> ans;
    if (B <= A.size())
    {
        for (int i = 0; i < B; i++)
        {
            um[A[i]]++;
        }
        ans.push_back(um.size());
        for (int i = B; i < A.size(); i++)
        {
            int leftIndex = i - B;
            if (um[A[leftIndex]] == 1)
            {
                um.erase(A[leftIndex]);
            }
            else
            {
                um[A[leftIndex]]--;
            }
            um[A[i]]++;
            ans.push_back(um.size());
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}