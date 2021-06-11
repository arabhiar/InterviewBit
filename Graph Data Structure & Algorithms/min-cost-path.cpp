#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> PII;

class Compare
{
public:
    bool operator()(PII p1, PII p2)
    {
        return p1.first > p2.first;
    }
};

int helper(int A, int B, vector<string> C)
{
    vector<vector<int>> cost(A, vector<int>(B, INT_MAX));
    cost[0][0] = 0;
    unordered_map<char, pair<int, int>> dir;
    dir['U'] = {-1, 0};
    dir['R'] = {0, 1};
    dir['D'] = {1, 0};
    dir['L'] = {0, -1};
    priority_queue< PII, vector<PII>, Compare> pq;
    pq.push({0, {0, 0}});
    while (!pq.empty())
    {
        auto topNode = pq.top();
        int row = topNode.second.first;
        int col = topNode.second.second;
        pq.pop();
        for (auto d : dir)
        {
            int rowIdx = row + d.second.first, colIdx = col + d.second.second;
            int weight = d.first == C[row][col] ? 0 : 1;
            if (rowIdx >= 0 && rowIdx < A && colIdx >= 0 && colIdx < B && (cost[rowIdx][colIdx] > cost[row][col] + weight))
            {
                cost[rowIdx][colIdx] = cost[row][col] + weight;
                pq.push({cost[rowIdx][colIdx], {rowIdx, colIdx}});
            }
        }
    }
    return cost[A - 1][B - 1];
}

int main()
{
    int A, B;
    cin >> A >> B;
    vector<string> C(A);
    for (int i = 0; i < A; i++)
        cin >> C[i];

    cout << helper(A, B, C);

    cout << endl;
    return 0;
}