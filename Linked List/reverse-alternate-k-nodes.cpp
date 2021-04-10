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

pair<ListNode *, ListNode *> reverseB(ListNode *node, int B)
{
    ListNode *curr = node, *prev = NULL, *next = NULL;
    while (curr != NULL && B > 0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        B--;
    }
    return {prev, next};
}

pair<ListNode *, ListNode *> skipB(ListNode *node, int B)
{
    ListNode *curr = node;
    while (curr && curr->next != NULL && B > 1)
    {
        curr = curr->next;
        B--;
    }
    return {curr, curr->next};
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

    ListNode *curr = A, *prev;
    int headFound = 0;
    ListNode *head;
    while (curr != NULL)
    {
        auto res = reverseB(curr, B);
        if (!headFound)
        {
            head = res.first;
            headFound = 1;
        }
        else
        {
            prev->next = res.first;
        }
        curr->next = res.second;
        curr = curr->next;
        if (curr != NULL)
        {
            auto temp = skipB(curr, B);
            prev = temp.first;
            curr = temp.second;
        }
    }

    // printLL(A);
    printLL(head);

    cout << endl;
    return 0;
}