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
    return (A && B) && (A->val == B->val) && helper(A->left, B->left) && helper(A->right, B->right);
}

int main()
{
    TreeNode *A = new TreeNode(1);
    A->left = new TreeNode(2);
    A->right = new TreeNode(3);
    A->left->left = new TreeNode(4);
    A->left->right = new TreeNode(5);
    A->right->left = new TreeNode(6);
    A->right->right = new TreeNode(7);
    A->left->left->left = new TreeNode(8);

    TreeNode *B = new TreeNode(1);
    B->left = new TreeNode(2);
    B->right = new TreeNode(3);
    B->left->left = new TreeNode(4);
    B->left->right = new TreeNode(5);
    B->right->left = new TreeNode(6);
    B->right->right = new TreeNode(7);
    B->left->left->left = new TreeNode(8);

    cout << helper(A, B);

    cout << endl;
    return 0;
}