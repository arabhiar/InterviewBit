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
    ListNode *prev = NULL, *curr = node, *next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
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
    int pos = 1;
    ListNode *oddHead = NULL, *evenHead = NULL, *p1 = NULL, *p2 = NULL;
    while (curr)
    {
        if (pos % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = curr;
                p2 = evenHead;
            }
            else
            {
                p2->next = curr;
                p2 = p2->next;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = curr;
                p1 = oddHead;
            }
            else
            {
                p1->next = curr;
                p1 = p1->next;
            }
        }
        curr = curr->next;
        pos++;
    }
    if (pos % 2 == 0)
    {
        p2->next = NULL;
    }
    else
    {
        p1->next = NULL;
    }
    ListNode *rev = reverseLL(evenHead);
    ListNode *dummy = new ListNode(-1);
    ListNode *p = dummy;

    while (rev && oddHead)
    {
        p->next = new ListNode(oddHead->val);
        p = p->next;
        p->next = new ListNode(rev->val);
        p = p->next;
        oddHead = oddHead->next;
        rev = rev->next;
    }

    while (oddHead)
    {
        p->next = new ListNode(oddHead->val);
        oddHead = oddHead->next;
        p = p->next;
    }
    while (rev)
    {
        p->next = new ListNode(rev->val);
        rev = rev->next;
        p = p->next;
    }

    printLL(dummy->next);

    cout << endl;
    return 0;
}