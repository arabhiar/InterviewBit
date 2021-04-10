#include <bits/stdc++.h>
using namespace std;

class MinStack
{
public:
    stack<int> s;
    stack<int> minStack;

    MinStack()
    {
        while (!s.empty())
        {
            s.pop();
        }
        while (!minStack.empty())
        {
            minStack.pop();
        }
    }

    void push(int val)
    {
        s.push(val);
        if (minStack.empty() || val <= minStack.top())
        {
            minStack.push(val);
        }
        else
        {
            minStack.push(minStack.top());
        }
    }

    void pop()
    {
        if (!s.empty())
        {
            minStack.pop();
            s.pop();
        }
    }

    int top()
    {
        return s.empty() ? -1 : s.top();
    }

    int getMin()
    {
        return minStack.empty() ? -1 : minStack.top();
    }
};

int main()
{
    MinStack obj;
    obj.push(10);
    obj.push(4);
    cout << obj.getMin() << "\n";
    obj.push(5);
    obj.push(8);
    obj.pop();
    obj.push(2);
    obj.push(5);
    cout << obj.getMin() << "\n";
    
    return 0;
}