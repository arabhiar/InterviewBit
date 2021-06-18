#include <bits/stdc++.h>
using namespace std;

bool isFound(vector<string> &A, string B, int i, int j)
{
    if (B.length() == 0)
        return true;
    if (i < 0 || j < 0 || i >= A.size() || j >= A[0].size() || A[i][j] != B[0])
        return false;
    char tmp = A[i][j];
    // A[i][j] = '#'; // if repeatation is not allowed
    bool res = isFound(A, B.substr(1), i + 1, j) || isFound(A, B.substr(1), i - 1, j) || isFound(A, B.substr(1), i, j + 1) || isFound(A, B.substr(1), i, j - 1);
    // A[i][j] = tmp;
    return res;
}

int helper(vector<string> A, string B)
{
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[i].size(); j++)
            if (isFound(A, B, i, j))
                return true;
    return false;
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    string B;
    cin >> B;

    cout << helper(A, B);

    cout << endl;
    return 0;
}