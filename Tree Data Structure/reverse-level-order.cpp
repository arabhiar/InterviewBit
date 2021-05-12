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

vector<int> helper(TreeNode *root)
{
    stack<int> s;
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *currNode;
    while (!q.empty())
    {
        int noOfNodes = q.size();
        for (int i = 0; i < noOfNodes; i++)
        {
            currNode = q.front();
            q.pop();
            s.push(currNode->val);
            if (currNode->right)
                q.push(currNode->right);
            if (currNode->left)
                q.push(currNode->left);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
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

    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;
    return 0;
}