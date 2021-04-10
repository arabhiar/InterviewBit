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

pair<ListNode *, ListNode *> reverseLL(ListNode *node, int l)
{
    ListNode *curr = node, *next = NULL, *prev = NULL;
    while (curr && l > 0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        l--;
    }
    return {prev, curr};
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
    int B, C;
    cin >> B >> C;
    ListNode *A = insert(vec);

    ListNode *curr = A, *prev = NULL, *newHead = NULL;
    int pos = 1;
    while (curr)
    {
        if (pos == B)
        {
            auto temp = reverseLL(curr, C - B + 1);
            if (prev == NULL)
            {
                newHead = temp.first;
                curr->next = temp.second;
            }
            else
            {
                newHead = A;
                prev->next = temp.first;
                curr->next = temp.second;
            }
            break;
        }
        prev = curr;
        curr = curr->next;
        pos++;
    }

    printLL(newHead);

    cout << endl;
    return 0;
}