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

bool find(TreeNode *root, int key)
{
    if (root == NULL)
        return false;

    if (root->val == key || find(root->left, key) || find(root->right, key))
        return true;

    return false;
}

TreeNode *findLCA(TreeNode *root, int &n1, int &n2, bool &found1, bool &found2)
{
    if (root == NULL)
        return NULL;

    if (root->val == n1)
    {
        found1 = true;
        return root;
    }

    if (root->val == n2)
    {
        found2 = true;
        return root;
    }

    auto leftLCA = findLCA(root->left, n1, n2, found1, found2);
    auto rightLCA = findLCA(root->right, n1, n2, found1, found2);

    if (leftLCA && rightLCA)
    {
        return root;
    }

    return leftLCA ? leftLCA : rightLCA;
}

int helper(TreeNode *A, int B, int C)
{
    bool found1 = false, found2 = false;
    auto lca = findLCA(A, B, C, found1, found2);
    if ((found1 && found2) || (found1 && find(lca, C)) || (found2 && find(lca, B)))
    {
        return lca->val;
    }
    return -1;
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
    int B, C;
    cin >> B >> C;

    cout << helper(root, B, C);

    cout << endl;
    return 0;
}