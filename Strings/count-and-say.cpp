#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;

    string s = "";

    for (int i = 0; i < A; i++)
    {
        if (i == 0)
        {
            s = "1";
        }
        else
        {
            string new_s = "";
            int count = 1;
            for (int i = 0; i < s.length() - 1; i++)
            {
                if (s[i] == s[i + 1])
                {
                    count++;
                }
                else
                {
                    new_s.append(to_string(count) + s[i]);
                    count = 1;
                }
            }
            new_s.append(to_string(count) + s[s.length() - 1]);
            s = new_s;
        }
    }

    cout << s;
    cout << endl;

    return 0;
}