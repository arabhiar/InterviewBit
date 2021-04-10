#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    getline(cin, A);
    vector<string> v;
    int start_idx = -1;
    int idx = 0;
    for (; A[idx] == ' '; idx++)
    {
    }
    A = A.substr(idx, A.length() - idx);
    for (idx = A.length() - 1; A[idx] == ' '; idx--)
    {
    }
    A = A.substr(0, idx + 1);
    for (int i = 0; i < A.length(); i++)
    {
        if (A[i] == ' ')
        {
            v.push_back(A.substr(start_idx + 1, i - start_idx - 1));
            while (A[i + 1] == ' ')
            {
                i++;
            }
            start_idx = i;
        }
    }
    v.push_back(A.substr(start_idx + 1, A.length() - start_idx - 1));
    reverse(v.begin(), v.end());
    string ans;
    for (int i = 0; i < v.size(); i++)
    {
        if (i == v.size() - 1)
        {
            ans += v[i];
        }
        else
        {
            ans += v[i] + " ";
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}