#include <bits/stdc++.h>
using namespace std;

int maxRectAreaHist(vector<int> vec)
{
    int maxArea = INT_MIN;
    stack<int> s;
    int currIdx, prevIdx, nextIdx, currArea;
    for (int i = 0; i < vec.size(); i++)
    {
        if (s.empty() || vec[i] >= vec[s.top()])
        {
            s.push(i);
        }
        else
        {
            while (!s.empty() && vec[s.top()] > vec[i])
            {
                currIdx = s.top();
                s.pop();
                prevIdx = s.empty() ? -1 : s.top();
                nextIdx = i;
                currArea = (nextIdx - prevIdx - 1) * vec[currIdx];
                maxArea = max(maxArea, currArea);
            }
            s.push(i);
        }
    }
    while (!s.empty())
    {
        currIdx = s.top();
        s.pop();
        prevIdx = s.empty() ? -1 : s.top();
        nextIdx = vec.size();
        currArea = (nextIdx - prevIdx - 1) * vec[currIdx];
        maxArea = max(maxArea, currArea);
    }
    return maxArea;
}

int helper(vector<vector<int>> A)
{
    vector<int> hist;
    hist.assign(A[0].begin(), A[0].end());
    int maxArea = maxRectAreaHist(hist);
    for (int i = 1; i < A.size(); i++)
    {
        for (int j = 0; j < A[i].size(); j++)
        {
            A[i][j] == 0 ? hist[j] = 0 : hist[j]++;
        }
        maxArea = max(maxArea, maxRectAreaHist(hist));
    }
    return maxArea;
}

int main()
{
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> A[i][j];

    cout << helper(A);

    cout << endl;
    return 0;
}