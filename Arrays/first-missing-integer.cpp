#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int currPos = 0, currNeg = n - 1;
        while (currPos < currNeg)
        {
            if (A[currPos] > 0)
            {
                currPos++;
            }
            if (A[currNeg] <= 0)
            {
                currNeg--;
            }
            if (A[currPos] <= 0 && A[currNeg] > 0)
            {
                swap(A[currPos], A[currNeg]);
                currPos++;
                currNeg--;
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << "\n";
        int positiveLength = currPos;

        if (A[currPos] > 0)
        {
            positiveLength++;
        }
        for (int i = 0; i < positiveLength; i++)
        {
            int x = abs(A[i]);
            if (x <= positiveLength)
            {
                A[x - 1] = -A[x - 1];
            }
        }

        int ans = positiveLength + 1;

        for (int i = 0; i < positiveLength; i++)
        {
            if (A[i] > 0)
            {
                ans = i + 1;
                break;
            }
        }
        cout << ans;
        cout << endl;
    }
}