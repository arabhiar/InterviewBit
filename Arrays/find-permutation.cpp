#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int B;
        cin >> B;
        string A;
        cin >> A;
        vector<int> vec;
        stack<int>s;
        for (int i = 0; i < B; i++)
        {
            s.push(i + 1);
            if (i < B - 1)
            {
                if (A[i] == 'I')
                {
                    while (!s.empty())
                    {
                        vec.push_back(s.top());
                        s.pop();
                    }
                }
            }
        }
        while (!s.empty())
        {
            vec.push_back(s.top());
            s.pop();
        }
        for (int i = 0; i < B; i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    // system("pause");
    return 0;
}