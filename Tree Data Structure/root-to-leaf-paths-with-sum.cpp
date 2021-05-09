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

void helper(TreeNode *A, int sum, int &req, vector<vector<int>> &ans, vector<int> track)
{
    track.push_back(A->val);
    sum += A->val;
    if (!A->left && !A->right)
    {
        if (sum == req)
        {
            ans.push_back(track);
        }
    }
    if (A->left)
    {
        helper(A->left, sum, req, ans, track);
    }
    if (A->right)
    {
        helper(A->right, sum, req, ans, track);
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
    root->right->right = new TreeNode(3);
    int B;
    cin >> B;

    vector<vector<int>> ans;
    vector<int> track;
    helper(root, 0, B, ans, track);

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