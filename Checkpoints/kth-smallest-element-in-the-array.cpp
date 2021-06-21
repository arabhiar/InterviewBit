#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A, int B)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto it : A)
        pq.push(it);
    for (int i = 0; i < B - 1; i++)
    {
        pq.pop();
    }
    return pq.top();
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int B;
    cin >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}