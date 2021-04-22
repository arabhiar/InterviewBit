#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

    unordered_map<char, int> freq;
    for (auto ch : B)
    {
        freq[ch]++;
    }
    unordered_map<char, int> temp;
    int start = 0, end = 0, matchCount = 0, minLen = INT_MAX;
    string ans;
    while (end < A.length() + 1)
    {
        if (matchCount < B.length())
        {
            temp[A[end]]++;
            if ((freq.find(A[end]) != freq.end()) && temp[A[end]] <= freq[A[end]])
            {
                matchCount++;
            }
            end++;
        }
        else
        {
            if (temp[A[start]] == 1)
            {
                temp.erase(A[start]);
            }
            else
            {
                temp[A[start]]--;
            }
            if (freq.find(A[start]) != freq.end() && (temp.find(A[start]) == temp.end() || temp[A[start]] < freq[A[start]]))
            {
                matchCount--;
            }
            start++;
        }
        if (matchCount == B.length())
        {
            if (end - start < minLen)
            {
                minLen = end - start;
                ans = A.substr(start, end - start);
            }
        }
    }

    cout << ans << endl;

    return 0;
}