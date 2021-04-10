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
    if (n <= 2)
        return n;
    int left = 2;
    for (int right = 2; right < n; right++)
    {
        if (A[left - 2] != A[right])
            A[left++] = A[right];
    }
    cout << left;
    cout << endl;

    return 0;
}