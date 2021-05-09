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

void helper(TreeNode *A, int &sum, int currSum)
{
    currSum = 10 * currSum + A->val;
    currSum %= 1003;
    if (!A->left && !A->right)
    {
        sum += currSum;
        sum %= 1003;
        return;
    }
    if (A->left)
    {
        helper(A->left, sum, currSum);
    }
    if (A->right)
    {
        helper(A->right, sum, currSum);
    }
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

    int sum = 0, currSum = 0;
    vector<int> track;
    track.push_back(root->val);
    helper(root, sum, currSum);

    cout << sum;

    cout << endl;
    return 0;
}