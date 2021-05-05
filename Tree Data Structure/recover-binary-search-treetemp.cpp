vector<int> Solution::recoverTree(TreeNode *A)
{
    auto curr = A;
    TreeNode *predecessor, *prev = NULL, *first = NULL, *second = NULL;
    while (curr)
    {
        if (curr->left == NULL)
        {
            if (prev != NULL && prev->val > curr->val)
            {
                if (first == NULL)
                {
                    first = prev;
                    second = curr;
                }
                else
                {
                    second = curr;
                }
            }
            prev = curr;
            curr = curr->right;
        }
        else
        {
            predecessor = curr->left;
            while (predecessor->right != NULL && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                // left part is already traversed
                predecessor->right = NULL;
                if (prev != NULL && prev->val > curr->val)
                {
                    if (first == NULL)
                    {
                        first = prev;
                        second = curr;
                    }
                    else
                    {
                        second = curr;
                    }
                }
                prev = curr;
                curr = curr->right;
            }
        }
    }
    vector<int> ans;
    ans.push_back(first->val);
    ans.push_back(second->val);
    sort(ans.begin(), ans.end());
    return ans;
}