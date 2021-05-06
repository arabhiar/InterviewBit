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

TreeNode *helper(TreeNode *A)
{
    // equivalent to postorder so that we already processed a node's right and left child.
    if (A == NULL)
    {
        return NULL;
    }
    A->left = helper(A->left);
    A->right = helper(A->right);
    if (A->left && A->right == NULL)
    {
        // only left child exists
        return A->left;
    }
    if (A->right && A->left == NULL)
    {
        // only right child exists
        return A->right;
    }
    return A;
}

int main()
{
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(6);
    // root->right = new TreeNode(3);
    // root->right->right = new TreeNode(7);

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->right = new TreeNode(5);

    print2D(root);
    auto newRoot = helper(root);
    print2D(newRoot);

    cout << endl;
    return 0;
}