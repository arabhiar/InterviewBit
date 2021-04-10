#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<string> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int r = n;
        int c = A[0].length();
        unordered_map<char, int> mapColor;
        mapColor.insert({'r', 0});
        mapColor.insert({'g', 1});
        mapColor.insert({'b', 2});
        vector<int> left(3, INT_MAX);
        vector<int> right(3, INT_MIN);
        vector<vector<int>> top(3, vector<int>(c, INT_MAX));
        vector<vector<int>> bottom(3, vector<int>(c, INT_MIN));
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                left[mapColor[A[i][j]]] = min(left[mapColor[A[i][j]]], j);
                right[mapColor[A[i][j]]] = max(right[mapColor[A[i][j]]], j);
            }
        }
        for (int j = 0; j < c; j++)
        {
            for (int i = 0; i < r; i++)
            {
                top[mapColor[A[i][j]]][j] = min(top[mapColor[A[i][j]]][j], i);
                bottom[mapColor[A[i][j]]][j] = max(top[mapColor[A[i][j]]][j], i);
            }
        }
        double ans = (double)1;
        for (int i = 0; i < c; i++)
        {
            for (int x = 0; x < 3; x++)
            {
                for (int y = 0; y < 3; y++)
                {
                    int z = 3 - x - y;
                    if (x != y && top[x][i] != INT_MAX && bottom[y][i] != INT_MIN && left[z] != INT_MAX)
                    {
                        ans = max(ans, ((double)1 / (double)2) * (bottom[y][i] - top[x][i] + 1) * (i - left[z] + 1));
                    }
                    if (x != y && top[x][i] != INT_MAX && bottom[y][i] != INT_MIN && right[z] != INT_MIN)
                    {
                        ans = max(ans, ((double)1 / (double)2) * (bottom[y][i] - top[x][i] + 1) * (right[z] - i + 1));
                    }
                }
            }
        }
        cout << ans;
        cout << endl;
    }
    // system("pause");
    return 0;
}