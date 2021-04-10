#include <bits/stdc++.h>
using namespace std;

int main()
{
    string A, B;
    cin >> A >> B;

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
    for (int i = l - 1; i >= 0; i--)
    {
        int curr_A_bit = A[i] - '0';
        int curr_B_bit = B[i] - '0';
        int temp = curr_A_bit ^ curr_B_bit;
        int out = carry ^ temp;
        int sum = carry ^ (curr_A_bit ^ curr_B_bit);
        carry = (curr_A_bit & curr_B_bit) | (carry & (curr_A_bit ^ curr_B_bit));
        ans += sum + '0';
    }
    if (carry)
    {
        ans += '1';
    }
    reverse(ans.begin(), ans.end());

    cout << ans;
    cout << endl;

    return 0;
}