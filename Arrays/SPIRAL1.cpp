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
        vector<vector<int>> vec(m, vector<int>(n));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> vec[i][j];
            }
        }
        int r_s = 0, r_e = vec.size(), c_s = 0, c_e = vec[0].size();
        while (r_s < r_e && c_s < c_e)
        {
            for (int i = c_s; i < c_e; i++)
            {
                cout << vec[r_s][i] << " ";
            }
            r_s++;
            for (int i = r_s; i < r_e; i++)
            {
                cout << vec[i][c_e - 1] << " ";
            }
            c_e--;
            if (r_s < r_e)
            {
                for (int i = c_e - 1; i >= c_s; i--)
                {
                    cout << vec[r_e - 1][i] << " ";
                }
                r_e--;
            }
            if (c_s < c_e)
            {
                for (int i = r_s; i < r_e; i++)
                {
                    cout << vec[i][c_s] << " ";
                }
            }

        }
        cout << endl;
    }
    return 0;
}