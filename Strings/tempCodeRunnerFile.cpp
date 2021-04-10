#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    if (regex_match(A, regex("[+-]?([0-9]*[.])?[0-9]+")))
    {
        cout << "Valid";
    }
    else
    {
        cout << "Not Valid";
    }
    return 0;
}