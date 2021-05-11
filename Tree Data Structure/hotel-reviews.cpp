#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
    return (p1.first > p2.first);
}

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

    unordered_set<string> us;
    string goodWord = "";
    for (auto ch : A)
    {
        if (ch == '_')
        {
            us.insert(goodWord);
            goodWord = "";
        }
        else
        {
            goodWord += ch;
        }
    }
    us.insert(goodWord);
    vector<pair<int, int>> freq;
    for (int i = 0; i < B.size(); i++)
    {
        goodWord = "";
        int count = 0;
        for (auto ch : B[i])
        {
            if (ch == '_')
            {
                if (us.find(goodWord) != us.end())
                {
                    count++;
                }
                goodWord = "";
            }
            else
            {
                goodWord += ch;
            }
        }
        if (us.find(goodWord) != us.end())
        {
            count++;
        }
        freq.push_back({count, i});
    }
    stable_sort(freq.begin(), freq.end(), compare);
    vector<int> ans;
    for (int i = 0; i < freq.size(); i++)
    {
        ans.push_back(freq[i].second);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}