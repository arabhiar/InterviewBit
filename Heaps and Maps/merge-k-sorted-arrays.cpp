#include <bits/stdc++.h>
using namespace std;

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> A[i][j];
        }
    }

    auto comp = [](auto &a, auto &b) { return a.first > b.first; };
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, decltype(comp)> minHeap(comp);
    for (int i = 0; i < A.size(); i++)
    {
        minHeap.push({A[i][0], {i, 0}});
    }
    vector<int> ans;
    while (!minHeap.empty())
    {
        auto curr = minHeap.top();
        int currMin = curr.first, i = curr.second.first, j = curr.second.second;
        minHeap.pop();
        ans.push_back(currMin);
        if (j + 1 < A[i].size())
        {
            minHeap.push({A[i][j + 1], {i, j + 1}});
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}