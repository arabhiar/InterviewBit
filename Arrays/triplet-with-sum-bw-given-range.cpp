#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        vector<float> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(stof(A[i]));
        }
        float a = temp[0], b = temp[1], c = temp[2];
        int ans = 0;
        for (int i = 3; i < n; i++)
        {
            if (a + b + c > 1 && a + b + c < 2)
            {
                ans = 1;
                break;
            }
            float curr = temp[i];
            if (a + b + c > 2)
            {
                if (a >= b && a >= c)
                {
                    a = curr;
                }
                else if (b >= a && b >= c)
                {
                    b = curr;
                }
                else
                {
                    c = curr;
                }
            }
            else
            {
                if (a <= b && a <= c)
                {
                    a = curr;
                }
                else if (b <= a && b <= c)
                {
                    b = curr;
                }
                else
                {
                    c = curr;
                }
            }
        }
        if (ans == 0 && a + b + c > 1 && a + b + c < 2)
        {
            ans = 1;
        }
        cout << ans;
        cout << "\n";
    }
    return 0;
}