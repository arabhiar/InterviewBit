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

    vector<int> ans;
    if (B > A.size())
    {
        ans.push_back(*max_element(A.begin(), A.end()));
    }
    else
    {
        deque<int> dq;
        int i;
        for (i = 0; i < B; i++)
        {
            while (!dq.empty() && A[dq.back()] <= A[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        while (i < A.size())
        {
            // i++;
            ans.push_back(A[dq.front()]);
            while (!dq.empty() && dq.front() <= i - B)
            {
                dq.pop_front();
            }
            while (!dq.empty() && A[dq.back()] <= A[i])
            {
                dq.pop_back();
            }
            dq.push_back(i);
            i++;
        }
        ans.push_back(A[dq.front()]);
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}