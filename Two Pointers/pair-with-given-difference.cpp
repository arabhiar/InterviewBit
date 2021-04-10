#include<bits/stdc++.h>
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
    int B;
    cin >> B;

    int i = 0;
    int j = i + 1;
    int ans = 0;
    sort(A.begin(), A.end());
    B = abs(B);
    while (i < A.size() && j < A.size())
    {
        int currDiff = A[j] - A[i];
        if (currDiff < B)
        {
            j++;
        }
        else if (currDiff > B)
        {
            i++;
            if (i == j)
            {
                j++;
            }
        }
        else
        {
            ans = 1;
            break;
        }
    }

    cout << ans;
    cout << endl;

    return 0;
}