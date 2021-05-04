#include <bits/stdc++.h>
using namespace std;

#define COUNT 3

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *insertNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        auto newNode = new TreeNode(data);
        return newNode;
    }
    if (data > root->val)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        root->left = insertNode(root->left, data);
    }
    return root;
}

TreeNode *getMax(TreeNode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

TreeNode *getMin(TreeNode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

TreeNode *searchNode(TreeNode *root, int data)
{
    if (root == NULL || root->val == data)
    {
        return root;
    }
    if (data > root->val)
    {
        return searchNode(root->right, data);
    }
    else
    {
        return searchNode(root->left, data);
    }
}

TreeNode *deleteNode(TreeNode *root, int data)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == data)
    {
        // Deletion Logic
        if (root->left == NULL)
        {
            return root->right;
        }
        if (root->right == NULL)
        {
            return root->left;
        }
        auto minRight = getMin(root->right);
        root->val = minRight->val;
        root->right = deleteNode(root->right, minRight->val);
    }
    else if (root->val < data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        root->left = deleteNode(root->left, data);
    }
    return root;
}

void preorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

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

TreeNode *parseBST(vector<int> A)
{
    TreeNode *root = NULL;
    for (auto it : A)
    {
        if (it != -1)
        {
            root = insertNode(root, it);
        }
    }
    return root;
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
    {
        cin >> vec[i];
    }
    TreeNode *root = parseBST(vec);

    print2D(root);
    cout << endl;

    // inorder(root);
    // cout << endl;
    // cout << "Min: " << getMin(root)->val << endl;
    // cout << "Max: " << getMax(root)->val << endl;

    // cout << endl;

    // deleteNode(root, 6);
    // inorder(root);
    // cout << endl;
    // cout << "Min: " << getMin(root)->val << endl;
    // cout << "Max: " << getMax(root)->val << endl;

    // cout << endl;

    // deleteNode(root, 7);
    // inorder(root);
    // cout << endl;
    // cout << "Min: " << getMin(root)->val << endl;
    // cout << "Max: " << getMax(root)->val << endl;

    // cout << endl;

    // deleteNode(root, 10);
    // inorder(root);
    // cout << endl;
    // cout << "Min: " << getMin(root)->val << endl;
    // cout << "Max: " << getMax(root)->val << endl;

    cout << endl;
    return 0;
}