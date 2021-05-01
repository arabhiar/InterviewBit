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
    int B;
    cin >> B;

    priority_queue<int> maxHeap;
    int ans = 0;
    for (auto it : A)
    {
        maxHeap.push(it);
    }
    for (int i = 0; i < B; i++)
    {
        int currMax = maxHeap.top();
        ans += currMax;
        maxHeap.pop();
        maxHeap.push(currMax - 1);
    }

    cout << ans;
    cout << endl;

    return 0;
}