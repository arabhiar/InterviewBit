#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        cin >> m >> n;
        vector<vector<int>> A(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> A[i][j];
            }
        }
        bool flag2 = false;
        for (int i = 0; i < n; i++)
        {
            if (A[0][i] == 0)
            {
                flag2 = true;
                break;
            }
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (A[i][j] == 0)
                {
                    A[i][0] = 0;
                    A[0][j] = 0;
                }
            }
        }
        bool flag1 = false;
        for (int i = 1; i < m; i++)
        {
            flag1 = A[i][0] == 0 ? true : false;
            for (int j = 0; j < n; j++)
            {
                if (flag1)
                {
                    A[i][j] = 0;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            flag1 = A[0][i] == 0 ? true : false;
            for (int j = 0; j < m; j++)
            {
                if (flag1)
                {
                    A[j][i] = 0;
                }
            }
        }
        if (flag2)
        {
            for (int i = 0; i < n; i++)
            {
                A[0][i] = 0;
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << A[i][j] << " ";
            }
            cout << "\n";
        }
        cout << "\n";
    }
}