#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    unordered_map<int, int> um;
    for (auto it : A)
    {
        um[it]++;
    }
    int majElement;
    int count = -1;
    for (auto it : um)
    {
        if (it.second > count)
        {
            majElement = it.first;
            count = it.second;
        }
    }
    return majElement;
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