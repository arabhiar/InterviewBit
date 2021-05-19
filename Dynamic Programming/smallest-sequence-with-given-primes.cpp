#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int A, int B, int C, int D)
{
    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(A);
    minHeap.push(B);
    minHeap.push(C);
    unordered_set<int> us;
    int count = 0;
    while (count < D)
    {
        int curr = minHeap.top();
        minHeap.pop();
        if (us.find(curr) == us.end())
        {
            us.insert(curr);
            ans.push_back(curr);
            count++;
            minHeap.push(curr * A);
            minHeap.push(curr * B);
            minHeap.push(curr * C);
        }
    }
    return ans;
}

int main()
{
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    auto ans = helper(A, B, C, D);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}