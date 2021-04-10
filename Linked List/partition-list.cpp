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
    int n;
    cin >> n;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    int B;
    cin >> B;
    ListNode *A = insert(vec);

    ListNode *dummy = new ListNode(0);
    ListNode *curr2 = dummy;
    ListNode *curr = A, *prev = NULL, *head = A, *next = NULL;
    while (curr != NULL)
    {
        next = curr->next;
        if (curr->val < B)
        {
            ListNode *temp = new ListNode(curr->val);
            if (prev == NULL)
            {
                head = curr->next;
                free(curr);
            }
            else
            {
                prev->next = next;
                free(curr);
            }
            curr2->next = temp;
            curr2 = curr2->next;
        }
        else
        {
            prev = curr;
        }
        curr = next;
    }
    curr2->next = head;

    printLL(dummy->next);

    cout << endl;
    return 0;
}