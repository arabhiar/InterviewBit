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
    ListNode *A = insert(vec);

    ListNode *curr = A, *prev = NULL, *head = A;
    int count_1 = 0;
    while (curr)
    {
        if (curr->val == 1)
        {
            count_1++;
            if (prev == NULL)
            {
                // head node
                curr = curr->next;
                head = curr;
                continue;
            }
            else
            {
                prev->next = curr->next;
            }
        }
        else
        {
            prev = curr;
        }
        // prev = curr;
        curr = curr->next;
    }
    while (count_1 > 0)
    {
        ListNode *temp = new ListNode(1);
        prev->next = temp;
        count_1--;
        prev = prev->next;
    }

    printLL(head);

    cout << endl;
    return 0;
}