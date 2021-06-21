#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, int B, int C)
{
    int i = 0, j = 0;
    int n = A.size();
    int sum = 0, count = 0;
    while (i < n)
    {
        sum += A[j];
        if (sum > C)
        {
            i++;
            j = i;
            sum = 0;
        }
        else if (sum < B)
        {
            j++;
        }
        else
        {
            count++;
            j++;
        }
        if (j == n)
        {
            sum = 0;
            i++;
            j = i;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int B, C;
    cin >> B >> C;

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}