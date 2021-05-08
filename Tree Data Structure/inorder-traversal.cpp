#include <bits/stdc++.h>
using namespace std;

#define COUNT 3

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Visualization of Tree
void print2DUtil(TreeNode *root, int space)
{
    if (root == NULL)
        return;
    space += COUNT;
    print2DUtil(root->right, space);
    cout << endl;
    for (int i = COUNT; i < space; i++)
        cout << " ";
    cout << root->val << "\n";
    print2DUtil(root->left, space);
}

void print2D(TreeNode *root)
{
    print2DUtil(root, 0);
}

// iterative approach for inorder traversal
vector<int> helper(TreeNode *A)
{
    // left -> root -> right
    auto curr = A;
    stack<TreeNode *> s;
    vector<int> ans;
    while (true)
    {
        if (curr == NULL && s.empty())
        {
            break;
        }
        // left
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        // root
        curr = s.top();
        s.pop();
        ans.push_back(curr->val);
        // right
        curr = curr->right;
    }
    return ans;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    auto ans = helper(root);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}