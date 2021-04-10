#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A;
    getline(cin, A);
    transform(A.begin(), A.end(), A.begin(), ::tolower);
    int n = A.length();
    int i = 0, j = n - 1;
    int flag = 1;
    while (i < n && j >= 0)
    {
        while (!isalnum(A[i]) && i < n)
        {
            i++;
        }
        while (!isalnum(A[j]) && j >= 0)
        {
            j--;
        }
        if (A[i] != A[j])
        {
            flag = 0;
            break;
        }
        i++;
        j--;
    }
    cout << flag;
    cout << "\n";
    return 0;
}