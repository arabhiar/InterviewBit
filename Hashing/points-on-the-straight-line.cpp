#include <bits/stdc++.h>
// #include <boost/functional/hash.hpp>
using namespace std;

struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    unordered_map<pair<int, int>, int, hash_pair> um;
    int overlapPoints, verticalPoints, currMax;
    int xDiff, yDiff;
    pair<int, int> p1, p2;
    int maxPoints = A.size() == 0 ? 0 : 1;
    for (int i = 0; i < A.size(); i++)
    {
        p1 = {A[i], B[i]};
        overlapPoints = verticalPoints = currMax = 0;
        for (int j = i + 1; j < A.size(); j++)
        {
            p2 = {A[j], B[j]};
            if (p1 == p2)
            {
                overlapPoints++;
            }
            else if (p1.first == p2.first)
            {
                verticalPoints++;
            }
            else
            {
                xDiff = p2.first - p1.first;
                yDiff = p2.second - p1.second;
                int h = __gcd(xDiff, yDiff);
                xDiff /= h;
                yDiff /= h;
                um[{xDiff, yDiff}]++;
                currMax = max(currMax, um[{xDiff, yDiff}]);
            }
            currMax = max(currMax, verticalPoints);
        }
        maxPoints = max(maxPoints, currMax + overlapPoints + 1);
        um.clear();
    }

    cout << maxPoints << endl;

    return 0;
}