#include <bits/stdc++.h>
using namespace std;

unordered_map<string, vector<string>> m;

vector<string> combine(string word, vector<string> prev)
{
    for (int i = 0; i < prev.size(); i++)
    {
        prev[i] += " " + word;
    }
    return prev;
}

vector<string> helper(string A, unordered_set<string> &dict)
{
    if (m.count(A))
        return m[A];
    vector<string> result;
    if (dict.count(A))
    {
        result.push_back(A);
    }
    for (int i = 1; i < A.length(); i++)
    {
        string word = A.substr(i);
        if (dict.count(word))
        {
            string rem = A.substr(0, i);
            auto prev = combine(word, helper(rem, dict));
            result.insert(result.end(), prev.begin(), prev.end());
        }
    }
    m[A] = result;
    return result;
}

int main()
{
    string A;
    cin >> A;
    int n;
    cin >> n;
    vector<string> B(n);
    for (int i = 0; i < n; i++)
        cin >> B[i];

    m.clear();

    unordered_set<string> dict;
    for (auto word : B)
        dict.insert(word);

    auto ans = helper(A, dict);
    sort(ans.begin(), ans.end());
    for (auto sentence : ans)
    {
        cout << sentence << endl;
    }

    return 0;
}