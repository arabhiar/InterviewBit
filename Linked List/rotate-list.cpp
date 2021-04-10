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

int getLength(ListNode *node)
{
    int length = 0;
    while (node != NULL)
    {
        node = node->next;
        length++;
    }
    return length;
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

    int len = getLength(A);
    int r = B % len;
    int l = len - r;
    int count = 0;
    ListNode *newHead;
    if (r == 0)
    {
        newHead = A;
    }
    else
    {
        ListNode *prev = NULL, *curr = A;
        while (curr != NULL && count < l && r != 0)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = NULL;
        newHead = curr;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = A;
    }

    printLL(newHead);

    cout << endl;
    return 0;
}