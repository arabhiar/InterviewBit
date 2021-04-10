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
    while (i < j)
    {
        if (A[j] - A[i] < B)
        {
            j++;
        }
        else if (A[j] - A[i] > B)
        {
            i++;
            if (i == j && i < A.size())
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