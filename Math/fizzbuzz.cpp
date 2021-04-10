#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A;
        cin >> A;
        vector<string> ans(A);
        for (int i = 0; i < A; i++)
        {
            if ((i + 1) % 3 == 0 && (i + 1) % 5 == 0)
            {
                ans[i] = "FizzBuzz";
            }
            else if ((i + 1) % 3 == 0)
            {
                ans[i] = "Fizz";
            }
            else if ((i + 1) % 5 == 0)
            {
                ans[i] = "Buzz";
            }
            else
            {
                ans[i] = to_string(i + 1);
            }
        }
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}