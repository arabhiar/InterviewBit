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

ListNode *helper(ListNode *A)
{
    if (A == NULL || A->next == NULL)
        return A;
    ListNode *origPrev, *revHead;
    ListNode *slow = A, *fast = A, *mid;
    while (fast && fast->next)
    {
        origPrev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    mid = slow;
    origPrev->next = NULL;

    ListNode *curr = mid, *temp, *prev = NULL, *next;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    revHead = prev;
    curr = A, temp = revHead;
    while (curr)
    {
        curr->val = (temp->val) - (curr->val);
        curr = curr->next;
        temp = temp->next;
    }
    curr = revHead, prev = NULL;
    while (curr)
    {
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    origPrev->next = prev;
    return A;
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

    printLL(helper(A));    

    cout << endl;
    return 0;
}