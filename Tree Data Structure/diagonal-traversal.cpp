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

void helper(TreeNode *A, int i, int j, map<int, vector<int>> &m)
{
    if (A == NULL)
    {
        return;
    }
    m[i - j].push_back(A->val);
    helper(A->left, i - 1, j + 1, m);
    helper(A->right, i + 1, j + 1, m);
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

    map<int, vector<int>> m;
    vector<int> ans;
    helper(root, 0, 0, m);
    for (auto it = m.rbegin(); it != m.rend(); it++)
    {
        for (auto i : it->second)
        {
            ans.push_back(i);
        }
    }

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}