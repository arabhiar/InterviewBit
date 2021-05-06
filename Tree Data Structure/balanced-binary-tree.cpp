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

int dfsHeight(TreeNode *root)
{
    // similar to post order traversal (postorder is used because it is bottom-up algo)
    if (root == NULL)
        return 0;
    int leftHeight = dfsHeight(root->left);
    if (leftHeight == -1)
        return -1; // if any node in left side found to be invalid directly return -1
    int rightHeight = dfsHeight(root->right);
    if (rightHeight == -1)
        return -1; // if any node in right side found to be invalid directly return -1
    if (abs(leftHeight - rightHeight) > 1)
    {
        return -1;
    }
    return 1 + max(leftHeight, rightHeight);
}

int helper(TreeNode *A)
{
    return dfsHeight(A) == -1 ? 0 : 1;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);

    int ans = helper(root);

    cout << ans;
    cout << endl;
    return 0;
}