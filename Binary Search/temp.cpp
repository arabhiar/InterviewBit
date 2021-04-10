// lower_bound/upper_bound example
#include <iostream>  // std::cout
#include <algorithm> // std::lower_bound, std::upper_bound, std::sort
#include <vector>    // std::vector

int main()
{
    int myints[] = {10, 20, 30, 30, 20, 10, 10, 20, 23};
    std::vector<int> v(myints, myints + 9); // 10 20 30 30 20 10 10 20 23

    std::sort(v.begin(), v.end()); // 10 10 10 20 20 20 23 30 30

    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 11); //          ^
    up = std::upper_bound(v.begin(), v.end(), 11);  //                   ^

    std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

    std::vector<int> v2({10, 30, 60, 100});
    int low2 = std::lower_bound(v2.begin(), v2.end(), 70, [](int a, int b) { return a <= b; }) - v2.begin();
    std::cout << "lower_bound at position " << (std::lower_bound(v2.begin(), v2.end(), 70) - v2.begin()) << '\n';
    std::cout << "upper_bound at position " << (std::upper_bound(v2.begin(), v2.end(), 70) - v2.begin()) << '\n';
    std::cout << "Using my comparator: " << low2 << "\n";

    return 0;
}