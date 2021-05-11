#include <bits/stdc++.h>
using namespace std;

#define CHAR_SIZE 26

// class for Trie
class Trie
{
    struct TrieNode
    {
        char val;
        int count;
        int endsHere;
        TrieNode *child[CHAR_SIZE];
    };

    // make a new TrieNode with given value.
    TrieNode *getNode(int idx)
    {
        TrieNode *newNode = new TrieNode;
        newNode->val = 'a' + idx;
        newNode->count = 0;
        newNode->endsHere = 0;
        for (int i = 0; i < CHAR_SIZE; i++)
        {
            newNode->child[i] = NULL;
        }
        return newNode;
    }

public:
    TrieNode *root;

    // constructor for Trie.
    Trie()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        root = getNode('/' - 'a');
    }

    // insert a given word in Trie.
    void insert(string word)
    {
        TrieNode *curr = root;
        int idx;
        for (auto ch : word)
        {
            idx = ch - 'a';
            if (curr->child[idx] == NULL)
            {
                curr->child[idx] = getNode(idx);
            }
            curr->child[idx]->count += 1;
            curr = curr->child[idx];
        }
        curr->endsHere += 1;
    }

    // search for a word in Trie.
    bool search(string word)
    {
        TrieNode *curr = root;
        int idx;
        for (auto ch : word)
        {
            idx = ch - 'a';
            if (curr->child[idx] == NULL)
            {
                return false;
            }
            curr = curr->child[idx];
        }
        return (curr->endsHere > 0);
    }

    // return true if at least one word exist with given prefix.
    bool startsWith(string prefix)
    {
        TrieNode *curr = root;
        int idx;
        for (auto ch : prefix)
        {
            idx = ch - 'a';
            if (curr->child[idx] == NULL)
            {
                return false;
            }
            curr = curr->child[idx];
        }
        return (curr->count > 0);
    }

    // count no of words starting with given prefix.
    int prefixWords(string prefix)
    {
        TrieNode *curr = root;
        int idx;
        for (auto ch : prefix)
        {
            idx = ch - 'a';
            if (curr->child[idx] == NULL)
            {
                return 0;
            }
            curr = curr->child[idx];
        }
        return curr ? curr->count : 0;
    }

    //  find shortest unique prefix for given list of words in trie.
    void shortestUniquePrefix(TrieNode *root, vector<string> &ans, string prefix)
    {
        if (root == NULL)
        {
            return;
        }
        if (root->count == 1)
        {
            ans.push_back(prefix);
            return;
        }
        for (auto child : root->child)
        {
            if (child)
                shortestUniquePrefix(child, ans, prefix + child->val);
        }
    }
};

int main()
{
    Trie *trie = new Trie();
    trie->insert("zebra");
    trie->insert("dog");
    trie->insert("duck");
    trie->insert("dove");

    cout << trie->search("hello") << endl;
    cout << trie->search("dove") << endl;
    cout << trie->prefixWords("do") << endl;

    cout << endl;
    return 0;
}