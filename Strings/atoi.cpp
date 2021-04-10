#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    int i = 0;
    for (; A[i] == ' '; i++)
    {
    }
    int flag = 1;
    if (A[i] == '+' || A[i] == '-')
    {
        if (A[i] == '-')
        {
            flag = 0;
        }
        i++;
    }
    long long int num = 0;
    while (A[i] >= '0' && A[i] <= '9')
    {
        num = num * 10 + (A[i] - '0');
        if (flag && num > INT_MAX)
        {
            num = INT_MAX;
            break;
        }
        if (!flag && num > ((long)INT_MAX + 1))
        {
            num = -1 * ((long)INT_MAX + 1);
            flag = 1;
            break;
        }
        i++;
    }
    if (!flag)
    {
        num = -1 * num;
    }
    cout << num;
    cout << endl;
    return 0;
}