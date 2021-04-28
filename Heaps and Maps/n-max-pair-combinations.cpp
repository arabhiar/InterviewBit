#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    priority_queue<pair<int, pair<int, int>>> maxHeap;
    set<pair<int, int>>s;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int a = A.size(), b = B.size();
    maxHeap.push({A[a - 1] + B[b - 1], {a - 1, b - 1}});
    vector<int> ans;
    int i, j, sum;
    for (int count = 0; count < a; count++)
    {
        auto curr = maxHeap.top();
        maxHeap.pop();
        ans.push_back(curr.first);
        i = curr.second.first;
        j = curr.second.second;
        s.insert({i, j});
        sum = A[i - 1] + B[j];
        if (s.find({i - 1, j}) == s.end())
        {
            maxHeap.push({sum, {i - 1, j}});
            s.insert({i - 1, j});
        }
        sum = A[i] + B[j - 1];
        if (s.find({i, j - 1}) == s.end())
        {
            maxHeap.push({sum, {i, j - 1}});
            s.insert({i, j - 1});
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}