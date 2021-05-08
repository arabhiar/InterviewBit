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

void helper(TreeNode *A, map<int, vector<int>> &m)
{
    if (A == NULL)
    {
        return;
    }
    queue<pair<TreeNode *, int>> q;
    int offset = 0;
    q.push({A, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        m[curr.second].push_back(curr.first->val);
        if (curr.first->left)
        {
            q.push({curr.first->left, curr.second - 1});
        }
        if (curr.first->right)
        {
            q.push({curr.first->right, curr.second + 1});
        }
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

    map<int, vector<int>> m;
    vector<vector<int>> ans;
    helper(root, m);
    for (auto it : m)
    {
        ans.push_back(it.second);
    }

    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    return 0;
}