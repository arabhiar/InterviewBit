#include <bits/stdc++.h>
using namespace std;

vector<int> helper(int A, vector<int> B)
{
    int minStrength = *min_element(B.begin(), B.end());
    int idx = min_element(B.begin(), B.end()) - B.begin();
    int maxKicks = A / minStrength;
    int currResistance = maxKicks * minStrength;
    int currIdx = 0;
    vector<int> ans;
    while (currIdx < idx && ans.size() < maxKicks)
    {
        if (currResistance - minStrength + B[currIdx] <= A)
        {
            ans.push_back(currIdx);
            currResistance = currResistance - minStrength + B[currIdx];
        }
        else
        {
            currIdx++;
        }
    }
    int rem = maxKicks - ans.size();
    while (rem)
    {
        ans.push_back(idx);
        rem--;
    }
    return ans;
}

int main()
{
    int A, n;
    cin >> A >> n;
    vector<int> B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    auto ans = helper(A, B);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}