#include <bits/stdc++.h>
using namespace std;

#define COUNT 3

// Tree structure
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

int curr = 0;

// helper function for soving problem
TreeNode *helper(int i, int j, const vector<int> &A, const vector<int> &B)
{
    if (curr < B.size())
    {
        if (i > j)
        {
            return NULL;
        }
        int idx = find(A.begin() + i, A.begin() + j + 1, B[curr]) - A.begin();
        TreeNode *newNode = new TreeNode(B[curr++]);
        newNode->left = helper(i, idx - 1, A, B);
        newNode->right = helper(idx + 1, j, A, B);
        return newNode;
    }
    return NULL;
}

int main()
{
    int n;
    cin >> n;
    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> B[i];
    }

    curr = 0;
    TreeNode *root = helper(0, A.size() - 1, B, A);
    print2D(root);

    cout << endl;
    return 0;
}