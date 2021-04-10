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

int getLLLength(ListNode *node)
{
    int count = 0;
    while (node)
    {
        count++;
        node = node->next;
    }
    return count;
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

    int l = getLLLength(A);
    ListNode *curr = A;
    int middlePos = (l / 2) + 1;
    int pos = middlePos - B;

    int ans;

    if (pos <= 0)
    {
        ans = -1;
    }
    else
    {
        while (curr && pos != 1)
        {
            curr = curr->next;
            pos--;
        }
        ans = curr->val;
    }
    
    cout << ans << endl;

    cout << endl;
    return 0;
}