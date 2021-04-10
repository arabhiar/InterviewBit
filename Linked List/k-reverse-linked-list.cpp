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

pair<ListNode *, ListNode *> reverseK(ListNode *node, int k)
{
    ListNode *curr = node, *prev = NULL, *next;
    while (curr != NULL && k > 0)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k--;
    }
    return {prev, next};
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
    dummy->next = A;
    ListNode *curr = A;
    ListNode *prev= dummy;
    while (curr != NULL)
    {
        auto res = reverseK(curr, B);
        prev->next = res.first;
        prev = curr;
        curr = res.second;
    }

    printLL(dummy->next);

    cout << endl;
    return 0;
}