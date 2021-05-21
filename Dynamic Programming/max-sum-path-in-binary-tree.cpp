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

// https://leetcode.com/problems/binary-tree-maximum-path-sum/discuss/603072/C%2B%2B-solution-O(n)-with-detailed-explanation

int helper(TreeNode *root, int &mps)
{
    if (root == NULL)
        return 0;
    int leftMax = max(helper(root->left, mps), 0);
    int rightMax = max(helper(root->right, mps), 0);
    mps = max(mps, leftMax + rightMax + root->val);
    return root->val + max(leftMax, rightMax);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(-1);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(-3);
    root->right->right = new TreeNode(-2);

    int mps = INT_MIN;
    helper(root, mps);
    cout << mps;

    cout << endl;
    return 0;
}