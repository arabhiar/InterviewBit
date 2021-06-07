#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, vector<int> B)
{
    int start = 0, total = 0, tank = 0;
    for (int i = 0; i < A.size(); i++)
        if ((tank = tank + A[i] - B[i]) < 0)
        {
            start = i + 1;
            total += tank;
            tank = 0;
        }
    return (total + tank < 0) ? -1 : start;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < n; i++)
        cin >> B[i];

    cout << helper(A, B);

    cout << endl;
    return 0;
}