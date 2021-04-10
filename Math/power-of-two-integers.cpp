#include <bits/stdc++.h>
using namespace std;

int main()
{

    unsigned int A;
    cin >> A;
    int ans = 0;
    if (A == 1)
    {
        ans = 1;
    }
    for (int i = 2; i <= sqrt(A); i++)
    {
        if (A % i == 0)
        {
            int temp = A;
            while (temp % i == 0)
            {
                temp = temp / i;
            }
            if (temp == 1)
            {
                ans = 1;
                break;
            }
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}