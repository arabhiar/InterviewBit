#include <bits/stdc++.h>
using namespace std;

// https://www.youtube.com/watch?v=vBdo7wtwlXs&t=256s

int helper(vector<int> A)
{
    if (A.size() <= 1)
        return 0;
    if (A[0] == 0)
        return -1;
    int ladder = A[0];
    int stairs = A[0];
    int jumps = 1;
    for (int level = 1; level < A.size(); level++)
    {
        if (level == A.size() - 1)
            return jumps;
        if (level + A[level] > ladder)
        {
            ladder = level + A[level];
        }
        stairs--;
        if (stairs == 0)
        {
            jumps++;
            if (level >= ladder)
                return -1;
            stairs = ladder - level;
        }
    }
    return jumps;
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