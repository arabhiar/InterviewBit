#include <bits/stdc++.h>
using namespace std;

class myComparision
{
public:
    bool operator()(const int a, const int b)
    {
        string s_a = to_string(a);
        string s_b = to_string(b);
        string c1 = s_a + s_b;
        string c2 = s_b + s_a;
        // cout << c1 << " " << c2 << " @ ";
        return c1 > c2;
    }
};

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
        sort(A.begin(), A.end(), myComparision());
        string result = "";
        for (int i = 0; i < n; i++)
        {
            result += to_string(A[i]);
        }
        unsigned int i = 0;
        while (true && i < result.length())
        {
            if (result[i] == '0')
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if (i == result.length())
        {
            result = "0";
        }
        else
        {
            result = result.substr(i, result.length() - i);
        }
        cout << result;
        cout << endl;
    }
    // system("pause");
    return 0;
}