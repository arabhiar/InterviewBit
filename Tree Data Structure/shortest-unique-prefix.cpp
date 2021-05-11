#include <bits/stdc++.h>
using namespace std;

#define CHAR_SIZE 26

struct TrieNode
{
    char val;
    int count;
    TrieNode *child[CHAR_SIZE];
    TrieNode(int idx)
    {
        val = 'a' + idx;
        count = 0;
        for (int i = 0; i < CHAR_SIZE; i++)
        {
            child[i] = NULL;
        }
    }
};

void insert(TrieNode *root, string word)
{
    int idx;
    TrieNode *curr = root;
    for (auto ch : word)
    {
        idx = ch - 'a';
        if (!curr->child[idx])
        {
            auto newNode = new TrieNode(idx);
            curr->child[idx] = newNode;
        }
        curr->child[idx]->count += 1;
        curr = curr->child[idx];
    }
}

string findPrefix(TrieNode *root, string word)
{
    TrieNode *curr = root;
    string prefix = "";
    int idx;
    for (auto ch : word)
    {
        idx = ch - 'a';
        if (!curr->child[idx])
        {
            break;
        }
        prefix += curr->child[idx]->val;
        if (curr->child[idx]->count == 1)
        {
            return prefix;
        }
        curr = curr->child[idx];
    }
    return prefix;
}

int main()
{
    int n;
    cin >> n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)
    {

        cin >> A[i];
    }

    vector<string> ans;
    auto root = new TrieNode('/' - 'a');
    for (auto word : A)
    {
        insert(root, word);
    }
    for (auto word : A)
    {
        ans.push_back(findPrefix(root, word));
    }

    for (auto str : ans)
    {
        cout << str << " ";
    }

    cout << endl;
    return 0;
}