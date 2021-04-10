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

    int i = 0, j = 0;
    while (i < A.size())
    {
        A[j] = A[i];
        while (A[i] == A[j])
        {
            i++;
        }
        j++;
    }

    for (int i = 0; i < j; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}