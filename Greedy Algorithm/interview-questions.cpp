#include <bits/stdc++.h>
using namespace std;

int helper(vector<int> A)
{
    bool prevState = true;
    int count = 0;
    for (auto bulb : A)
    {
        if (bulb == 0 && prevState)
        {
            count++;
            prevState = false;
        }
        else if (bulb == 1 && !prevState)
        {
            count++;
            prevState = true;
        }
    }
    return count;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];

    cout << helper(A);

    cout << endl;
    return 0;
}