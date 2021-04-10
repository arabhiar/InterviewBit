#include <bits/stdc++.h>
using namespace std;

// regex b("\\s*[+-]?([0-9]*[.])?([0-9]*[e])?[+-]?([0-9]+)\\s*"); regex solution

int main()
{
    string A;
    cin >> A;
    int ans = 0;

    int i = 0;
    for (; A[i] == ' '; i++)
    {
    }

    if (A[i] == '-' || A[i] == '+')
        i++;
    int n_pt, n_nm, n_pt_nm;

    for (n_nm = 0, n_pt = 0, n_pt_nm = -1; (A[i] <= '9' && A[i] >= '0') || A[i] == '.'; i++)
    {
        A[i] == '.' ? n_pt++ : n_nm++;
        if (n_pt == 1)
        {
            n_pt_nm++;
        }
    }

    if (n_pt > 1 || n_nm < 1 || (n_pt == 1 && n_pt_nm < 1))
    {
        ans = 0;
    }
    else
    {
        if (A[i] == 'e')
        {
            i++;
            if (A[i] == '+' || A[i] == '-')
            {
                i++;
            }
            int n_nm = 0;
            for (; A[i] <= '9' && A[i] >= '0'; i++, n_nm++)
            {
            }
            if (n_nm < 1)
            {
                ans = 0;
            }
        }
        for (; A[i] == ' '; i++)
        {
        }
        ans = A[i] == 0;
    }

    cout << ans;
    cout << endl;
    return 0;
}