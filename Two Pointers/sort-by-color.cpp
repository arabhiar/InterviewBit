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

    int i = 0, j = A.size() - 1;
    for (int k = 0; k < A.size(); k++)
    {
        if (A[k] == 0)
        {
            i++;
        }
        if (A[k] == 2)
        {
            j--;
        }
    }

    cout << i << " " << j << endl;
    for (int k = 0; k < i; k++)
    {
        A[k] = 0;
    }
    for (int k = i; k <= j; k++)
    {
        A[k] = 1;
    }
    for (int k = j + 1; k < A.size(); k++)
    {
        A[k] = 2;
    }

    for (auto it : A)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}