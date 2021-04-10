#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B;
    cin >> B;
    int low = 0;
    int high = *max_element(A.begin(), A.end());
    int ans = 0;
    while (low <= high)
    {
        int currHeight = low + (high - low) / 2;
        long long int currWood = 0;
        for (auto h : A)
        {
            if (currHeight < h)
            {
                currWood += (h - currHeight);
            }
        }
        if (currWood >= (long)B)
        {
            low = currHeight + 1;
            ans = max(ans, currHeight);
        }
        else
        {
            high = currHeight - 1;
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}