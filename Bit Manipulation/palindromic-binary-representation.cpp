#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;

    int len = 0;
    int count = 0;

    while (count < A)
    {
        len++;
        count += pow(2, (len - 1) / 2);
    }

    int offset = pow(2, (len - 1) / 2) - (count - A) - 1;

    string temp = bitset<32>(offset).to_string();
    int i = 0;
    while (temp[i] == '0' && i < 32 - ((len - 1) / 2))
    {
        i++;
    }
    string half = "1" + temp.substr(i, 32 - i);
    string temp2 = half.substr(0, len / 2);
    reverse(temp2.begin(), temp2.end());
    string binary_ans = half + temp2;

    // cout << binary_ans << "\n";

    int ans = stoi(binary_ans, nullptr, 2);

    cout << ans;

    // cout << len << " " << count << " " << offset;
    cout << endl;

    return 0;
}