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

TreeNode *helper(int i, int j, vector<int> A)
{
    if (i > j)
    {
        return NULL;
    }
    int maxIdx = max_element(A.begin() + i, A.begin() + j + 1) - A.begin();
    TreeNode *newNode = new TreeNode(A[maxIdx]);
    newNode->left = helper(i, maxIdx - 1, A);
    newNode->right = helper(maxIdx + 1, j, A);
    return newNode;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    TreeNode *root = helper(0, A.size() - 1, A);

    cout << endl;
    return 0;
}