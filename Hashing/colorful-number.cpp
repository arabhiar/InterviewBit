#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A;
    cin >> A;

    vector<int> vec;
    while (A)
    {
        vec.insert(vec.begin(), A % 10);
        A /= 10;
    }

    unordered_map<long long int, long long int> myMap;
    int flag = 0;
    int ans = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        long long int value = 1;
        if (flag)
        {
            break;
        }
        for (int j = i; j < vec.size(); j++)
        {
            value = value * vec[j];
            if (myMap.find(value) != myMap.end())
            {
                ans = 0;
                flag = 1;
                break;
            }
            myMap.insert({value, value});
        }
    }

    cout << ans << endl;
    return 0;
}