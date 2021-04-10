#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    int B;
    cin >> B;

    vector<string> result;
    for (int i = 0, j; i < A.size(); i = j)
    {   int width = 0;
        for (j = i; j < A.size() && width + A[j].size() + j - i <= B; j++)
        {
            width += A[j].size();
        }
        int space = 1;
        int extra = 0;
        if (j - i != 1 && j != A.size())
        {
            space = (B - width) / (j - i - 1);
            extra = (B - width) % (j - i - 1);
        }
        string line(A[i]);
        for (int k = i + 1; k < j; k++)
        {
            line += string(space, ' ');
            if (extra-- > 0)
            {
                line += " ";
            }
            line += A[k];
        }

        line += string(B - line.size(), ' ');
        result.push_back(line);
    }
    
    return 0;

}