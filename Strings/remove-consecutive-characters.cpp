#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    int B;
    cin >> A;
    cin >> B;

    int i = 0;
    int n = A.length();
    string res = "";

    while (i < n)
    {
        int j;
        int flag = 1;
        for (j = i; j < i + B; j++)
        {
            if (A[j] != A[i])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            res += A.substr(i, j - i);
        }
        i = j;
    }

    cout << res;
    cout << endl;

    return 0;
}