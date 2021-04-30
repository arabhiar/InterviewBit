#include <bits/stdc++.h>
using namespace std;

#define M 1000000007

int main()
{
    int n;
    cin >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }
    int A;
    cin >> A;

    priority_queue<int> maxHeap;
    for (auto it : B)
    {
        maxHeap.push(it);
    }
    long long int ans = 0;
    for (int i = 0; i < A; i++)
    {
        int maxNo = maxHeap.top();
        maxHeap.pop();
        ans += maxNo;
        ans %= M;
        maxHeap.push(floor(maxNo / 2));
    }

    cout << ans << endl;

    return 0;
}