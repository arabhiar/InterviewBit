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

int helper(TreeNode *root, int k)
{
    stack<TreeNode *> s1, s2;
    int lo, hi;
    TreeNode *curr1 = root, *curr2 = root;
    while (curr1)
    {
        s1.push(curr1);
        lo = curr1->val;
        curr1 = curr1->left;
    }
    while (curr2)
    {
        s2.push(curr2);
        hi = curr2->val;
        curr2 = curr2->right;
    }
    int sum;
    while (lo < hi)
    {
        sum = lo + hi;
        if (sum < k)
        {
            // do one step of inorder
            while (curr1)
            {
                s1.push(curr1);
                lo = curr1->val;
                curr1 = curr1->left;
            }
            auto temp = s1.top();
            lo = temp->val;
            curr1 = temp->right;
            s1.pop();
        }
        else if (sum > k)
        {
            // do one step of reverse inorder
            while (curr2)
            {
                s2.push(curr2);
                hi = curr2->val;
                curr2 = curr2->right;
            }
            auto temp = s2.top();
            hi = temp->val;
            curr2 = temp->left;
            s2.pop();
        }
        else
        {
            return 1;
        }
    }
    return 0;
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
    TreeNode *A = parseBST(vec);
    int B;
    cin >> B;

    // print2D(A);
    // cout << endl;

    int ans = helper(A, B);

    cout << ans;
    cout << endl;
    return 0;
}