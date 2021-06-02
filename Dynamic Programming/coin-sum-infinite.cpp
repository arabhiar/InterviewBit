#include <bits/stdc++.h>
using namespace std;

int M = 1e6 + 7;

int helper(vector<int> A, int B)
{
    vector<int> prev(B + 1, 0);
    prev[0] = 1;
    vector<int> curr(B + 1);
    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < curr.size(); j++)
        {
            if (j == 0)
            {
                curr[0] = 1;
            }
            else
            {
                int temp = 0;
                if (j - A[i] >= 0)
                {
                    temp += curr[j - A[i]];
                    temp %= M;
                }
                temp += prev[j];
                temp %= M;
                curr[j] = temp;
            }
        }
        prev = curr;
    }
    return curr[B];
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int B;
    cin >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}