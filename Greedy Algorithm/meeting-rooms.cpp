#include <bits/stdc++.h>
using namespace std;

// https://guides.codepath.com/compsci/Scheduling-Meeting-Rooms
int helper(vector<vector<int>> A)
{
    priority_queue<int, vector<int>, greater<int>> pq; // gives meetings with earliest end time.
    for (auto meet : A)
    {
        pq.push(meet[1]);
    }
    sort(A.begin(), A.end());
    int count = 0;
    for (auto meet : A)
    {
        if (!pq.empty() && meet[0] < pq.top())
        {
            // some meeting is going on hence another room required.
            count++;
        }
        else
        {
            pq.pop();
        }
    }
    return count;
}

int solve(vector<vector<int>> &A)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    sort(A.begin(), A.end());
    for (auto &i : A)
    {
        pq.push(i[1]);
    }
    int ans = 0;
    for (int i = 0; i < A.size(); ++i)
    {
        if (!pq.empty() && A[i][0] >= pq.top())
            pq.pop();
        else
            ++ans;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(2));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}