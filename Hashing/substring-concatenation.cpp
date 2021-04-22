#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    cin >> A;
    int n;
    cin >> n;
    vector<string> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    vector<int> ans;
    if (B.size() > 0 && B[0].length() <= A.length())
    {
        int wordLength = B[0].length();
        int words = B.size();
        unordered_map<string, int> um, temp;
        for (auto st : B)
        {
            um[st]++;
        }
        for (int i = 0; i + (words * wordLength) <= A.size(); i++)
        {
            string subA = A.substr(i, words * wordLength);
            for (int j = 0; j < subA.size(); j += wordLength)
            {
                temp[subA.substr(j, wordLength)]++;
            }
            if (temp == um)
            {
                ans.push_back(i);
            }
            temp.clear();
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}