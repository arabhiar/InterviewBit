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
    int ans = -1;
    if (B > 0 && B <= A.size())
    {

        int low = *max_element(A.begin(), A.end());
        int high = accumulate(A.begin(), A.end(), 0);

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int studentsReq = 1, currSum = 0;

            for (int i = 0; i < n; i++)
            {
                currSum += A[i];

                if (currSum > mid)
                {
                    currSum = A[i];
                    studentsReq++;
                }
            }
            if (studentsReq <= B)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        ans = low;
    }
    cout << ans;
    cout << endl;
    return 0;
}