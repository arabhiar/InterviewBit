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

ListNode *reverseLL(ListNode *node)
{
    ListNode *curr = node, *prev = NULL, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

ListNode *getMiddleNode(ListNode *node)
{
    ListNode *slow = node, *fast = node;
    while (fast && fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    ListNode *A = insert(vec);

    ListNode *curr = A;
    ListNode *middle = getMiddleNode(curr);
    ListNode *head1 = A;
    ListNode *temp = middle->next;
    middle->next = NULL;
    ListNode *head2 = reverseLL(temp);

    // 1 -> 2 -> 3
    // 6 -> 5 -> 4
    // 1 -> 6 -> 2 -> 5 -> 3 -> 4
    ListNode *p1 = head1, *p2 = head2, *prev = NULL;

    while (p1 && p2)
    {
        ListNode *next1 = p1->next;
        ListNode *next2 = p2->next;
        if (!prev)
        {
            p1->next = p2;
        }
        else
        {
            prev->next = p1;
            p1->next = p2;
        }
        prev = p2;
        p1 = next1;
        p2 = next2;
    }
    while (p1)
    {
        if (prev == NULL)
        {
            prev = p1;
        }
        else
        {
            prev->next = p1;
        }
        prev = prev->next;
        p1 = p1->next;
    }

    while (p2)
    {
        if (prev == NULL)
        {
            prev = p2;
        }
        else
        {
            prev->next = p2;
        }
        prev = prev->next;
        p2 = p2->next;
    }

    printLL(head1);

    cout << endl;
    return 0;
}