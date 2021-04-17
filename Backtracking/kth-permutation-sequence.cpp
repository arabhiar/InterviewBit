#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n > 12)
    {
        return INT_MAX;
    }
    int f = 1;
    for (auto i = 2; i <= n; ++i)
        f *= i;
    return f;
}

string kthPer(vector<int> &temp, int k)
{
    int l = temp.size();
    if (l == 0 || k > fact(l))
        return "";
    int block_size = fact(l - 1);
    int idx = (k - 1) / block_size;
    string st = to_string(temp[idx]);
    k -= idx * block_size;
    temp.erase(temp.begin() + idx);
    return st + kthPer(temp, k);
}

int main()
{
    int A, B;
    cin >> A >> B;

    vector<int> temp;
    for (int i = 1; i <= A; i++)
    {
        temp.push_back(i);
    }
    string ans = kthPer(temp, B);

    cout << ans;
    cout << endl;

    return 0;
}