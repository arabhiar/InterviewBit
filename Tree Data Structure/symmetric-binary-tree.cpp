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

bool helper(TreeNode *A, TreeNode *B)
{
    if (A == NULL && B == NULL)
    {
        return true;
    }
    return (A && B) && (A->val == B->val) && helper(A->left, B->right) && helper(A->right, B->left);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);

    cout << helper(root, root);

    cout << endl;
    return 0;
}