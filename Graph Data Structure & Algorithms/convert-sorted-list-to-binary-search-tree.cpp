TreeNode *helper(vector<int> &A, int i, int j)
{
    if (i > j)
        return NULL;
    int m = (i + j) / 2;
    auto newNode = new TreeNode(A[m]);
    newNode->left = helper(A, i, m - 1);
    newNode->right = helper(A, m + 1, j);
    return newNode;
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    vector<int> arr;
    while (A)
    {
        arr.push_back(A->val);
        A = A->next;
    }
    return helper(arr, 0, arr.size() - 1);
}