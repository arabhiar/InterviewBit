#include <bits/stdc++.h>
using namespace std;

// a + b + c + d + e = S    eq-1
// a^2 + b^2 + c^2 + d^2 + e^2 = SS    eq-2

// a + b + b + d + e = s    eq-3
// a^2 + b^2 + b^2 + d^2 + e^2 = ss    eq-4

// eq-1 - eq-3 => c - b = S - s
// eq-2 - eq-4 => c^2 - b^2 = SS - ss => (c - b) * (c + b) = SS - ss => (S - s) * (c + b) = SS - ss => (c + b) = (SS - ss) / (S - s)

// c - b = S - s && c + b = (SS - ss) / (S - s)


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++)
        {
            cin >> A[i];
        }
        vector<long long int> ans;
        // long long int linearSum = (n * (n + 1)) / 2;
        // long long int squareSum = (n * (n + 1) * (2 * n + 1)) / 6;
        long long int diffLinearSum = 0, diffSquareSum = 0;
        for (int i = 0; i < n; i++)
        {
            long long int j = i + 1;
            long long int temp = (long long int)A[i];
            diffLinearSum += (j - temp);
            diffSquareSum += (j + temp) * (j - temp);
        }
        long long int x = diffLinearSum;       // equivalent to (a + b)
        long long int y = diffSquareSum / x; //equivalent to  (a - b)

        long long int a = abs((x + y) / 2);
        long long int b = abs((x - y) / 2);

        if (diffLinearSum > 0)
        {
            ans.push_back(min(a, b));
            ans.push_back(max(a, b));
        }
        else
        {
            ans.push_back(max(a, b));
            ans.push_back(min(a, b));
        }

        for (auto item : ans)
        {
            cout << item << " ";
        }
        cout << "\n";
    }
    return 0;
}