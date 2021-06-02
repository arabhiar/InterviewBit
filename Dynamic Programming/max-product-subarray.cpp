#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    int minNegEndingHere = 1, maxPosEndingHere = -1, maxSoFar;
    if (A.size() == 0)
        return 0;
    A[0] < 0 ? minNegEndingHere = A[0] : maxPosEndingHere = A[0];
    maxSoFar = A[0];
    for (int i = 1; i < A.size(); i++)
    {
        if (A[i] >= 0)
        {
            maxPosEndingHere = max(A[i], maxPosEndingHere * A[i]);
            minNegEndingHere = A[i] * minNegEndingHere;
        }
        else
        {
            int temp = minNegEndingHere;
            minNegEndingHere = min(A[i], maxPosEndingHere * A[i]);
            maxPosEndingHere = A[i] * temp;
        }
        maxSoFar = max(maxSoFar, maxPosEndingHere);
    }
    return maxSoFar;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}