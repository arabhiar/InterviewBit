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
    int B;

    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    cin >> B;
    ListNode *A = insert(vec);

    int len = getLength(A);
    int l = (B > len) ? 1 : (len - B + 1);
    int count = 1;
    ListNode *curr = A, *prev = NULL, *head = A;
    while (curr != NULL)
    {
        if (count == l)
        {
            if (prev == NULL)
            {
                head = head->next;
            }
            else
            {
                prev->next = curr->next;
            }
            break;
        }
        count++;
        prev = curr;
        curr = curr->next;
    }

    printLL(head);
    cout << getLength(A);

    cout << endl;
    return 0;
}