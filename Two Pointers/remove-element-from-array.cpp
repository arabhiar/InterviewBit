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
    int i = 0, j= 0;
    while (i < A.size())
    {
        if (A[i] != B)
        {
            A[j] = A[i];
            i++;
            j++;
        }
        else
        {
            i++;
        }
    }
    for (int k = 0; k < j; k++)
    {
        cout << A[k] << " ";
    }
    cout << endl;
    return 0;
}