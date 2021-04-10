#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int A;
        cin >> A;

        int r_s = 0, c_s = 0;
        int r_e = A, c_e = A;
        vector<vector<int>> ans(A, vector<int>(A, 0));
        int count = 1;
        while (r_s < r_e && c_s < c_e)
        {
            for (int i = c_s; i < c_e; i++)
            {
                ans[r_s][i] = count;
                count++;
            }
            r_s++;
            for (int i = r_s; i < r_e; i++)
            {
                ans[i][c_e - 1] = count;
                count++;
            }
            c_e--;
            if (r_s < r_e)
            {
                for (int i = c_e - 1; i >= c_s; i--)
                {
                    ans[r_e - 1][i] = count;
                    count++;
                }
                r_e--;
            }
            if (c_s < c_e)
            {
                for (int i = r_e - 1; i >= r_s; i--)
                {
                    ans[i][c_s] = count;
                    count++;
                }
                c_s++;
            }
        }
        for (int i = 0; i < A; i++)
        {
            for (int j = 0; j < A; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}