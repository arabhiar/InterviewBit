#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(vector<int> &path, TreeNode *A, int B)
{
    if (!A)
    {
        return false;
    }
    path.push_back(A->val);
    if (A->val == B)
    {
        return true;
    }
    if (helper(path, A->left, B) || helper(path, A->right, B))
    {
        return true;
    }
    path.pop_back();
    return false;
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(7);
    int B;
    cin >> B;

    vector<int> ans;
    helper(ans, root, B);

    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}