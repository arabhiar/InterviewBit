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
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    ListNode *A = insert(vec);

    ListNode *dummy = new ListNode(0);
    dummy->next = A;
    ListNode *prev = dummy, *curr = A;
    while (curr != NULL)
    {
        while (curr->next != NULL && curr->next->val == prev->next->val)
        {
            curr = curr->next;
        }
        if (prev->next == curr)
        {
            prev = prev->next;
        }
        else
        {
            prev->next = curr->next;
        }
        curr = curr->next;
    }

    ListNode *newHead = dummy->next;
    printLL(newHead);

    cout << endl;
    return 0;
}