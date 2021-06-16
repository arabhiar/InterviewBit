#include <bits/stdc++.h>
using namespace std;

vector<vector<string>> helper(string A, string B, vector<string> &C)
{
    unordered_set<string> dict(C.begin(), C.end());
    dict.insert(B);
    queue<vector<string>> q;
    vector<string> path;
    vector<vector<string>> ans;
    path.push_back(A);
    q.push(path);
    unordered_set<string> visited;
    int minLevel = INT_MAX;
    if (A == B)
    {
        ans.push_back({A});
        return ans;
    }
    while (!q.empty())
    {
        int n = q.size();
        for (auto s : visited)
        {
            dict.erase(s);
        }
        visited.clear();
        if (path.size() > minLevel)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            path = q.front();
            q.pop();
            string word = path.back();
            for (int j = 0; j < word.length(); j++)
            {
                char t = word[j];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[j] = c;
                    if (dict.find(word) != dict.end())
                    {
                        auto newPath = path;
                        newPath.push_back(word);
                        visited.insert(word);
                        if (word == B)
                        {
                            minLevel = newPath.size();
                            ans.push_back(newPath);
                        }
                        else
                        {
                            q.push(newPath);
                        }
                    }
                }
                word[j] = t;
            }
        }
    }
    return ans;
}

int main()
{
    string A, B;
    cin >> A >> B;
    int n;
    cin >> n;
    vector<string> C(n);
    for (int i = 0; i < n; i++)
        cin >> C[i];

    auto ans = helper(A, B, C);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}