#include<bits/stdc++.h>
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
    vector<int> ans;
    for (auto it : A)
    {
        maxHeap.push(it);
    }
    for (int i = 0; i < B; i++)
    {
        ans.push_back(maxHeap.top());
        maxHeap.pop();
    }

    for (auto it: ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}