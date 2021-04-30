#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    int C;
    cin >> C;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    auto comp = [](auto &a, auto &b) {
        return a.first < b.first;
    };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> maxHeap(comp);
    int i = A.size() - 1;
    int j = B.size() - 1;
    maxHeap.push({A[i] + B[j], {i, j}});
    set<pair<int, int>> s;
    vector<int> ans;
    int sum;
    for (int count = 0; count < C; count++)
    {
        auto currMax = maxHeap.top();
        maxHeap.pop();
        i = currMax.second.first;
        j = currMax.second.second;
        ans.push_back(currMax.first);
        s.insert({i, j});
        sum = A[i] + B[j - 1];
        if (s.find({i, j - 1}) == s.end())
        {
            s.insert({i, j - 1});
            maxHeap.push({sum, {i, j - 1}});
        }
        sum = A[i - 1] + B[j];
        if (s.find({i - 1, j}) == s.end())
        {
            s.insert({i - 1, j});
            maxHeap.push({sum, {i - 1, j}});
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}