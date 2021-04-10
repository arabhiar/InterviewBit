#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    int count_5 = 0;
    int ans = 0;
    if (A >= 5)
    {
        for (int i = 5; i <= A; i += 5)
        {
            int temp = i;
            while (temp % 5 == 0)
            {
                temp /= 5;
                count_5++;
            }
        }
        ans = count_5;
    }
    cout << ans;
    cout << endl;
    return 0;
}