#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int A, int B)
{
    vector<int> ans;
    for (int i = 0; i <= 9; i++)
    {
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            if (curr >= A && curr <= B)
                ans.push_back(curr);
            if (i == 0 || curr > B)
                continue;
            int d = curr % 10;
            int num1 = curr * 10 + (d - 1);
            int num2 = curr * 10 + (d + 1);
            if (d == 0)
            {
                q.push(num2);
            }
            else if (d == 9)
            {
                q.push(num1);
            }
            else
            {
                q.push(num1);
                q.push(num2);
            }
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main()
{
    int A, B;
    cin >> A >> B;

    auto ans = helper(A, B);
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

    cout << endl;
    return 0;
}