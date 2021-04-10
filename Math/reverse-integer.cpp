#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;
    string str = to_string(A);
    int flag = 0;
    if (A < 0)
    {
        flag = 1;
        str = str.substr(1);
    }
    std::reverse(str.begin(), str.end());
    if (flag)
    {
        str = "-" + str;
    }
    int ans = 0;
    try
    {
        int temp = stoi(str);
        ans = temp;
    }
    catch (...)
    {
        ans = 0;
    }
    cout << ans << endl;
    return 0;
}