#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> A(R, vector<int>(C, 0));
        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> A[i][j];
            }
        }
        int B;
        cin >> B;
        int new_r = R - B + 1;
        vector<vector<int>> stripSum(new_r, vector<int>(C, 0));
        for (int i = 0; i < C; i++)
        {
            int sum = 0;
            for (int j = 0; j < B; j++)
            {
                sum += A[j][i];
            }
            stripSum[0][i] = sum;
            for (int j = 1; j < new_r; j++)
            {
                sum += (A[j + B - 1][i] - A[j - 1][i]);
                stripSum[j][i] = sum;
            }
        }

        int max_sum = INT_MIN;
        for (int i = 0; i < new_r; i++)
        {
            int sum = 0;
            for (int j = 0; j < B; j++)
            {
                sum += stripSum[i][j];
            }
            max_sum = max(max_sum, sum);
            for (int j = 1; j < C - B + 1; j++)
            {
                sum += (stripSum[i][j + B - 1] - stripSum[i][j - 1]);
                max_sum = max(max_sum, sum);
            }
        }

        cout << max_sum;
        cout << endl;
    }
}