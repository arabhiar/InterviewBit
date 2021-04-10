#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int zero_bit = 0, one_bit = 0;
    for (int i = 0; i < A.size(); i++)
    {
        zero_bit = (zero_bit ^ A[i]) & ~one_bit;
        one_bit = (one_bit ^ A[i]) & ~zero_bit;
    }
    cout << zero_bit;
    cout << endl;
    return 0;
}