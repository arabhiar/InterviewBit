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

vector<vector<int>> helper(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
    {
        return ans;
    }
    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    TreeNode *currNode;
    s1.push(root);
    while (!s1.empty() || !s2.empty())
    {
        vector<int> temp;
        while (!s1.empty())
        {
            currNode = s1.top();
            s1.pop();
            temp.push_back(currNode->val);
            if (currNode->left)
                s2.push(currNode->left);
            if (currNode->right)
                s2.push(currNode->right);
        }
        if (temp.size() > 0)
            ans.push_back(temp);
        temp.clear();
        while (!s2.empty())
        {
            currNode = s2.top();
            s2.pop();
            temp.push_back(currNode->val);
            if (currNode->right)
                s1.push(currNode->right);
            if (currNode->left)
                s1.push(currNode->left);
        }
        if (temp.size() > 0)
            ans.push_back(temp);
        temp.clear();
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