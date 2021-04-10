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
        vector<int> vec(n);
        for (int i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        vector<int> v(n);
        v[n - 1] = vec[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            if (v[i + 1] < vec[i])
            {
                v[i] = vec[i];
            }
            else
            {
                v[i] = v[i + 1];
            }
        }
        int sum = 0;
        set<int> s;
        s.insert(vec[0]);
        for (int i = 1; i < n - 1; i++)
        {
            s.insert(vec[i]);
            int b = vec[i];
            int c = v[i + 1];
            if (c > b)
            {
                auto it = s.find(b);
                if (it != s.begin())
                {
                    int a = *(--it);
                    sum = max(sum, a + b + c);
                }
            }
        }
        cout << sum;
        cout << endl;
    }
    // system("pause");
    return 0;
}