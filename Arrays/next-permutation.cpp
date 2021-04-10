#include <bits/stdc++.h>
using namespace std;

// class myComparision
// {
// public:
//     bool operator()(const int a, const int b)
//     {
//         string s_a = to_string(a);
//         string s_b = to_string(b);
//         string c1 = s_a + s_b;
//         string c2 = s_b + s_a;
//         // cout << c1 << " " << c2 << " @ ";
//         return c1 > c2;
//     }
// };

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        int idx1 = -1, idx2;
        for (int i = n - 2; i >= 0; i--)
        {
            if (A[i + 1] > A[i])
            {
                idx1 = i;
                break;
            }
        }
        if (idx1 == -1)
        {
            sort(A.begin(), A.end());
        }
        else
        {
            for (int i = n - 1; i >= 0; i--)
            {
                if (A[i] > A[idx1])
                {
                    idx2 = i;
                    break;
                }
            }
            swap(A[idx1], A[idx2]);
            sort(A.begin() + idx1 + 1, A.end());
        }
        for (int i = 0; i < n; i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}