#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insert(vector<int> vec)
{
    if (vec.size() == 0)
    {
        return NULL;
    }
    ListNode *head = new ListNode(vec[0]);
    ListNode *prev = head;
    for (int i = 1; i < vec.size(); i++)
    {
        ListNode *temp = new ListNode(vec[i]);
        prev->next = temp;
        prev = prev->next;
    }
    return head;
}

void printLL(ListNode *head)
{
    if (head == NULL)
    {
        cout << "Empty Linked List!\n";
    }
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int k;
    cin >> k;
    int n;
    vector<ListNode *> A;
    for (int i = 0; i < k; i++)
    {
        cin >> n;
        vector<int> temp(n);
        for (int i = 0; i < n; i++)
        {
            cin >> temp[i];
        }
        A.push_back(insert(temp));
    }

    auto comp = [](ListNode *a, ListNode *b) {
        return a->val > b->val;
    };
    priority_queue<ListNode *, vector<ListNode *>, decltype(comp)> minHeap(comp);
    vector<ListNode *> itr;
    for (int i = 0; i < A.size(); i++)
    {
        minHeap.push(A[i]);
    }
    ListNode *newHead = NULL, *ptr = NULL;
    while (!minHeap.empty())
    {
        auto currNode = minHeap.top();
        minHeap.pop();
        if (newHead == NULL)
        {
            newHead = currNode;
            ptr = currNode;
        }
        else
        {
            ptr->next = currNode;
            ptr = ptr->next;
        }
        if (currNode->next != NULL)
        {
            minHeap.push(currNode->next);
        }
    }

    printLL(newHead);

    return 0;
}