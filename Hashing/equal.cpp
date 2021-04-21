#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    vector<int> ans;
    if (A.size() > 3)
    {
        unordered_map<int, pair<int, int>> um;
        for (int i = 0; i < A.size() - 1; i++)
        {
            for (int j = i + 1; j < A.size(); j++)
            {
                int currSum = A[i] + A[j];
                if (um.find(currSum) == um.end())
                {
                    um[currSum] = {i, j};
                }
                else
                {
                    if (um.find(currSum) != um.end())
                    {
                        int a = um[currSum].first;
                        int b = um[currSum].second;
                        int c = i;
                        int d = j;
                        if (a < b && c < d && a < c && b != d && b != c)
                        {
                            vector<int> temp;
                            temp.push_back(a);
                            temp.push_back(b);
                            temp.push_back(c);
                            temp.push_back(d);
                            if (ans.size() == 0)
                            {
                                ans = temp;
                            }
                            else
                            {
                                if (lexicographical_compare(temp.begin(), temp.end(), ans.begin(), ans.end()))
                                {
                                    ans = temp;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}