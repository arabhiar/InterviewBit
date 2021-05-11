#include <bits/stdc++.h>
using namespace std;

#define COUNT 3

struct TreeNode
{
    int val;
    TreeNode *left, *right, *next;
    TreeNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
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

void helper(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *currNode, *prevNode;
    while (!q.empty())
    {
        int noOfNodes = q.size();
        for (int i = 0; i < noOfNodes; i++)
        {
            currNode = q.front();
            q.pop();
            if (i != 0)
            {
                currNode->next = prevNode;
            }
            if (currNode->right)
            {
                q.push(currNode->right);
            }
            if (currNode->left)
            {
                q.push(currNode->left);
            }
            prevNode = currNode;
        }
    }
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);

    helper(root);

    cout << endl;
    return 0;
}