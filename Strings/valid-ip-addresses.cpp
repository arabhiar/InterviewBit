#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;

    vector<string> ans;
    for (int a = 1; a <= 3; a++)
    {
        for (int b = 1; b <= 3; b++)
        {
            for (int c = 1; c <= 3; c++)
            {
                for (int d = 1; d <= 3; d++)
                {
                    if (a + b + c + d == A.length())
                    {
                        int first = stoi(A.substr(0, a));
                        int second = stoi(A.substr(a, b));
                        int third = stoi(A.substr(a + b, c));
                        int fourth = stoi(A.substr(a + b + c, d));
                        if (first <= 255 && second <= 255 && third <= 255 && fourth <= 255)
                        {
                            // cout << first << "." << second << "." << third << "." << fourth << endl;
                            string ip = to_string(first) + "." + to_string(second) + "." + to_string(third) + "." + to_string(fourth);
                            if (ip.length() == A.length() + 3)
                            {
                                ans.push_back(ip);
                            }
                        }
                    }
                }
            }
        }
    }
    sort(ans.begin(), ans.end());

    for (auto ip : ans)
    {
        cout << ip << endl;
    }

    return 0;
}