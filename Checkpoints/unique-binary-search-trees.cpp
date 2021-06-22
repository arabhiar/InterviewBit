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

vector<TreeNode *> helper(int start, int end)
{
    vector<TreeNode *> nodeList;
    if (start > end)
    {
        nodeList.push_back(NULL);
        return nodeList;
    }
    for (int i = start; i <= end; i++)
    {
        auto leftSubtree = helper(start, i - 1);
        auto rightSubtree = helper(i + 1, end);
        for (int j = 0; j < leftSubtree.size(); j++)
        {
            auto left = leftSubtree[j];
            for (int k = 0; k < rightSubtree.size(); k++)
            {
                auto right = rightSubtree[k];
                auto newNode = new TreeNode(i);
                newNode->left = left;
                newNode->right = right;
                nodeList.push_back(newNode);
            }
        }
    }
    return nodeList;
}

int main()
{
    int A;
    cin >> A;

    auto ans = helper(1, A);

    for (auto root : ans)
        print2D(root);

    cout << endl;
    return 0;
}