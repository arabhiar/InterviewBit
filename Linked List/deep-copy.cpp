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

ListNode *deepCopy(ListNode *head)
{
    ListNode *newHead = NULL, *ptr = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        auto temp = new ListNode(curr->val);
        if (!newHead)
        {
            newHead = temp;
            ptr = temp;
            curr = curr->next;
            continue;
        }
        else
        {
            ptr->next = temp;
        }
        ptr = ptr->next;
        curr = curr->next;
    }
    return newHead;
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

    auto newHead = deepCopy(A);
    printLL(A);
    printLL(newHead);

    cout << endl;
    return 0;
}