#include <bits/stdc++.h>
using namespace std;

string mul_help(string s, char c)
{
    if (c == '0')
    {
        return "0";
    }
    int l = s.length();
    int b = c - '0';
    int carry = 0;
    string ans = "";
    for (int i = l - 1; i >= 0; i--)
    {
        int curr_digit = s[i] - '0';
        int temp = (curr_digit * b) + carry;
        ans += (temp % 10) + '0';
        carry = temp / 10;
    }
    if (carry)
    {
        ans += carry + '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string add_help(string A, string B)
{
    int len_A = A.length();
    int len_B = B.length();
    if (len_A > len_B)
    {
        string s(len_A - len_B, '0');
        B = s + B;
    }
    else if (len_B > len_A)
    {
        string s(len_B - len_A, '0');
        A = s + A;
    }
    int l = A.length();
    int carry = 0;
    string ans = "";
    for (int j = l - 1; j >= 0; j--)
    {
        int curr_A = A[j] - '0';
        int curr_B = B[j] - '0';
        int temp = curr_A + curr_B + carry;
        ans += (temp % 10) + '0';
        carry = temp / 10;
    }
    if (carry)
    {
        ans += carry + '0';
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

string mul(string A, string B)
{
    string prev = "";
    for (int i = 0; i < B.length(); i++)
    {
        string temp = mul_help(A, B[i]);
        prev = add_help(prev, temp);
        if (i != B.length() - 1)
        {
            prev += '0';
        }
    }
    return prev;
}

int main()
{
    string A, B;
    cin >> A >> B;

    int i = 0, j = 0;
    while (A[i] == '0' && i != A.length() - 1)
    {
        i++;
    }
    while (B[j] == '0' && j != B.length() - 1)
    {
        j++;
    }
    A = A.substr(i);
    B = B.substr(j);
    cout << mul(A, B);
    cout << endl;

    return 0;
}