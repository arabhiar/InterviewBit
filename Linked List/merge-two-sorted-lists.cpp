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
    while (head->next != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << head->val << endl;
}

int main()
{
    int m, n;
    cin >> m >> n;

    vector<int> vec1(m);
    vector<int> vec2(n);
    for (int i = 0; i < m; i++)
    {
        cin >> vec1[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> vec2[i];
    }
    ListNode *A = insert(vec1);
    ListNode *B = insert(vec2);

    ListNode *ptr1 = A, *ptr2 = B;
    ListNode *newHead = new ListNode(0);
    ListNode *curr = newHead;

    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1->val <= ptr2->val)
        {
            curr->next = new ListNode(ptr1->val);
            ptr1 = ptr1->next;
        }
        else
        {
            curr->next = new ListNode(ptr2->val);
            ptr2 = ptr2->next;
        }
        curr = curr->next;
    }

    while (ptr1 != NULL)
    {
        curr->next = new ListNode(ptr1->val);
        curr = curr->next;
        ptr1 = ptr1->next;
    }

    while (ptr2 != NULL)
    {
        curr->next = new ListNode(ptr2->val);
        curr = curr->next;
        ptr2 = ptr2->next;
    }

    printLL(newHead->next);

    cout << endl;
    return 0;
}