/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode* Solution::copyRandomList(RandomListNode* A) {
    RandomListNode *curr = A;
    RandomListNode *newHead = NULL, *ptr = NULL;
    unordered_map<RandomListNode *, RandomListNode *> um;
    while (curr != NULL)
    {
        RandomListNode *temp = new RandomListNode(curr->label);
        um[curr] = temp;
        if (newHead == NULL)
        {
            newHead = temp;
            ptr = temp;
            curr = curr->next;
            continue;
        }
        else
        {
            ptr->next = temp;
            ptr = ptr->next;
        }
        curr = curr->next;
    }
    
    curr = A;
    ptr = newHead;
    while (curr != NULL)
    {
        ptr->random = um[curr->random];
        ptr = ptr->next;
        curr = curr->next;
    }
    return newHead;
}
