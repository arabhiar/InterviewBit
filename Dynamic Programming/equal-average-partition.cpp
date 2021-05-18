#include <bits/stdc++.h>
using namespace std;

vector<vector<vector<bool>>> dp;
vector<int> res;
vector<int> original;
int total_size;

bool possible(int idx, int curr_sum, int curr_size)
{
    if (curr_size == 0)
        return curr_sum == 0;

    if (idx >= total_size)
        return false;
    if (dp[idx][curr_sum][curr_size] == false) return false;
    if (curr_sum >= original[idx])
    {
        res.push_back(original[idx]);
        if (possible(idx + 1, curr_sum - original[idx], curr_size - 1))
            return true;
        res.pop_back();
    }
    if (possible(idx + 1, curr_sum, curr_size))
        return true;
    return dp[idx][curr_sum][curr_size] = false;
}

vector<vector<int>> helper(vector<int> &A)
{
    sort(A.begin(), A.end());
    original.clear();
    original = A;
    res.clear();
    dp.clear();

    int total_sum = 0;
    total_size = A.size();
    for (auto it : A)
        total_sum += it;

    dp.resize(original.size(), vector<vector<bool>>(total_sum + 1, vector<bool>(total_size, true)));

    for (int i = 1; i < total_size; i++)
    {
        if ((total_sum * i) % total_size != 0)
            continue;
        int set1_sum = (total_sum * i) / total_size;
        if (possible(0, set1_sum, i))
        {
            int ptr1 = 0, ptr2 = 0;
            vector<int> res1 = res;
            vector<int> res2;
            while (ptr1 < A.size() || ptr2 < res.size())
            {
                if (ptr2 < res.size() && res[ptr2] == A[ptr1])
                {
                    ptr1++;
                    ptr2++;
                    continue;
                }
                res2.push_back(A[ptr1]);
                ptr1++;
            }

            vector<vector<int>> ans;
            ans.push_back(res1);
            ans.push_back(res2);
            return ans;
        }
    }
    vector<vector<int>> ans;
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    auto ans = helper(A);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}