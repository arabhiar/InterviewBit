#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<pair<int, int>> vec;
    vec.push_back({1, 1});
    vec.push_back({2, 4});
    vec.push_back({3, 9});
    vec.push_back({4, 16});
    vec.push_back({5, 25});
    vec.push_back({6, 36});

    for (auto item : vec)
    {
        cout << item.first << " " << item.second;
        cout << endl;
    }
    cout << endl;
}