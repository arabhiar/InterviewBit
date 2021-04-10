#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string A;
        cin >> A;
        int n = A.length();
        int l = 0, r = 0;
        int temp = 0;
        int ans = INT_MIN;
        int L, R;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == '1')
            {
                c++;
            }
        }
        vector<int> res;
        if (c == n)
        {
            cout << "No requirement of swapping.";
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (A[i] == '0')
                {
                    temp++;
                    r = i;
                }
                else
                {
                    temp--;
                    if (temp < 0)
                    {
                        temp = 0;
                        r = i + 1;
                        l = i + 1;
                    }
                }
                if (temp > ans)
                {
                    ans = temp;
                    L = l;
                    R = r;
                }
            }
            cout << L + 1 << " " << R + 1;
            res.push_back(L + 1);
            res.push_back(R + 1);
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}