#include <bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>> &A)
{
    // int n = A.size() - 1;
    // int maxValue = INT_MIN;
    // unsigned int i, j;
    // for (i = 0; i < A.size(); i++)
    // {
    //     maxValue = max(maxValue, *max_element(A[i].begin(), A[i].end()));
    // }
    // maxValue++;
    // for (i = 0; i < A.size(); i++)
    // {
    //     for (j = 0; j < A[i].size(); j++)
    //     {
    //         int i_new = j;
    //         int j_new = n - i;
    //         A[i_new][j_new] = (A[i][j] % maxValue) * maxValue + (A[i_new][j_new] % maxValue);
    //     }
    // }
    // for (i = 0; i < A.size(); i++)
    // {
    //     for (j = 0; j < A[i].size(); j++)
    //     {
    //         A[i][j] = A[i][j] / maxValue;
    //     }
    // }

    int n = A.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            swap(A[i][j], A[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(A[i][j], A[i][n - j - 1]);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> A(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> A[i][j];
        }
        rotate(A);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}