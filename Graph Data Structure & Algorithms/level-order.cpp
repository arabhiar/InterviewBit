#include <bits/stdc++.h>
using namespace std;

#define COUNT 3

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int getHeight(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int lHeight = getHeight(root->left);
    int rHeight = getHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

vector<vector<int>> helper(TreeNode *A)
{
    int h = getHeight(A);
    vector<vector<int>> ans(h);
    if (A == NULL)
    {
        return ans;
    }
    queue<pair<TreeNode *, int>>q;
    q.push({A, 0});
    while (!q.empty())
    {
        auto curr = q.front();
        q.pop();
        auto currNode = curr.first;
        int currLevel = curr.second;
        ans[currLevel].push_back(currNode->val);
        if (currNode->left)
        {
            q.push({currNode->left, currLevel + 1});
        }
        if (currNode->right)
        {
            q.push({currNode->right, currLevel + 1});
        }
    }
    return ans;
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

    auto ans = helper(root);
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