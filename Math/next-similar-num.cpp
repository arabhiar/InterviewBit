#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    int l = A.size();
    int i = l - 1;
    while (i > 0)
    {
        if (A[i - 1] < A[i])
        {
            break;
        }
        i--;
    }
    int idx1 = i - 1, idx2 = -1;
    string ans;
    if (idx1 < 0)
    {
        ans = "-1";
    }
    else
    {
        string subString = A.substr(idx1 + 1);
        string s1(1, A[idx1]);
        for (int i = stoi(s1) + 1; i <= 9; i++)
        {
            size_t found = subString.find(to_string(i));
            if (found != string::npos)
            {
                idx2 = found + idx1 + 1;
                break;
            }
        }
        swap(A[idx1], A[idx2]);
        sort(A.begin() + idx1 + 1, A.end());
        ans = A;
    }
    cout << ans;
    return 0;
}