#include <bits/stdc++.h>
using namespace std;

bool allNine(string str)
{
    for (auto c : str)
    {
        if (c != '9')
        {
            return false;
        }
    }
    return true;
}

bool isPalindrome(string str)
{
    string newStr = str;
    reverse(newStr.begin(), newStr.end());
    return str == newStr;
}

int main()
{
    string A;
    cin >> A;
    int l = A.length();
    string ans = "";

    if (allNine(A))
    {
        ans += "1" + string(l - 1, '0') + "1";
    }
    else if (l == 1)
    {
        char temp = (((A[0] - '0') + 1) + '0');
        ans += temp;
    }
    else if (isPalindrome(A))
    {
        if (l % 2 == 0)
        {
            // even length
            int midIdx = (l / 2) - 1;
            int carry = ((A[midIdx] - '0') + 1) / 10;
            A[midIdx] = (((A[midIdx] - '0') + 1) % 10) + '0';
            int idx = midIdx - 1;
            while (idx >= 0 && carry)
            {
                carry = ((A[idx] - '0') + 1) / 10;
                A[idx] = (((A[idx] - '0') + 1) % 10) + '0';
                idx--;
            }
            string firstHalf = A.substr(0, midIdx + 1);
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(), secondHalf.end());
            ans = firstHalf + secondHalf;
        }
        else
        {
            // odd length
            int midIdx = (l / 2);
            int carry = ((A[midIdx] - '0') + 1) / 10;
            A[midIdx] = (((A[midIdx] - '0') + 1) % 10) + '0';
            int idx = midIdx - 1;
            while (idx >= 0 && carry)
            {
                carry = ((A[idx] - '0') + 1) / 10;
                A[idx] = (((A[idx] - '0') + 1) % 10) + '0';
                idx--;
            }
            string firstHalf = A.substr(0, midIdx);
            string secondHalf = firstHalf;
            reverse(secondHalf.begin(), secondHalf.end());
            ans = firstHalf + A[midIdx] + secondHalf;
        }
    }
    else
    {
        if (l % 2 == 0)
        {
            int midIdx = l / 2 - 1;
            int left = midIdx;
            int right = midIdx + 1;
            while (left >= 0 && right < l)
            {
                if (A[left] == A[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    if (A[left] > A[right])
                    {
                        string firstHalf = A.substr(0, midIdx + 1);
                        string secondHalf = firstHalf;
                        reverse(secondHalf.begin(), secondHalf.end());
                        ans = firstHalf + secondHalf;
                        break;
                    }
                    else
                    {
                        int carry = ((A[midIdx] - '0') + 1) / 10;
                        A[midIdx] = (((A[midIdx] - '0') + 1) % 10) + '0';
                        int idx = midIdx - 1;
                        while (idx >= 0 && carry)
                        {
                            carry = ((A[idx] - '0') + 1) / 10;
                            A[idx] = (((A[idx] - '0') + 1) % 10) + '0';
                            idx--;
                        }
                        string firstHalf = A.substr(0, midIdx + 1);
                        string secondHalf = firstHalf;
                        reverse(secondHalf.begin(), secondHalf.end());
                        ans = firstHalf + secondHalf;
                        break;
                    }
                }
            }
        }
        else
        {
            int midIdx = l / 2;
            int left = midIdx - 1;
            int right = midIdx + 1;
            while (left >= 0 && right < l)
            {
                if (A[left] == A[right])
                {
                    left--;
                    right++;
                }
                else
                {
                    if (A[left] > A[right])
                    {
                        string firstHalf = A.substr(0, midIdx);
                        string secondHalf = firstHalf;
                        reverse(secondHalf.begin(), secondHalf.end());
                        ans = firstHalf + A[midIdx] + secondHalf;
                        break;
                    }
                    else
                    {
                        int midIdx = (l / 2);
                        int carry = ((A[midIdx] - '0') + 1) / 10;
                        A[midIdx] = (((A[midIdx] - '0') + 1) % 10) + '0';
                        int idx = midIdx - 1;
                        while (idx >= 0 && carry)
                        {
                            carry = ((A[idx] - '0') + 1) / 10;
                            A[idx] = (((A[idx] - '0') + 1) % 10) + '0';
                            idx--;
                        }
                        string firstHalf = A.substr(0, midIdx);
                        string secondHalf = firstHalf;
                        reverse(secondHalf.begin(), secondHalf.end());
                        ans = firstHalf + A[midIdx] + secondHalf;
                        break;
                    }
                }
            }
        }
    }
    cout << ans;
    cout << endl;
    return 0;
}