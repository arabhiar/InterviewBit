#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> a, int b)
{
    if (b == 0)
    {
        return 0;
    }
    int i = 0, j = 0;
    int count = 0;
    unordered_map<int, int> um;
    while (i < a.size() && j < a.size())
    {
        if (um.find(a[j]) == um.end())
        {
            // not found
            um[a[j]] = 0;
        }
        um[a[j]]++;

        while (um.size() > b)
        {
            um[a[i]]--;
            if (um[a[i]] == 0)
            {
                um.erase(a[i]);
            }
            i++;
        }

        count += (j - i + 1);
        j++;
    }
    return count;
}

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

    cout << helper(A, B) - helper(A, B - 1);
    cout << endl;

    return 0;
}