/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

int ans;

void helper(TreeNode *curr, int &count, int k)
{
    if (curr == NULL)
    {
        return;
    }
    //  cout << curr->val << endl;
    helper(curr->left, count, k);
    count = count + 1;
    if (count == k)
    {
        ans = curr->val;
    }
    helper(curr->right, count, k);
}

int Solution::kthsmallest(TreeNode *A, int B)
{
    // int ans = 0;
    int count = 0;
    helper(A, count, B);
    return ans;
}
