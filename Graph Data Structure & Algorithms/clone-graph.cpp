/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
// #include<bits/stdc++.h>
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node)
{
    if (!node)
        return NULL;
    UndirectedGraphNode *clone = new UndirectedGraphNode(node->label);
    unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> clones;
    clones[node] = clone;
    queue<UndirectedGraphNode *> q;
    q.push(node);
    while (!q.empty())
    {
        UndirectedGraphNode *curr = q.front();
        q.pop();
        for (auto n : curr->neighbors)
        {
            if (clones.find(n) == clones.end())
            {
                clones[n] = new UndirectedGraphNode(n->label);
                q.push(n);
            }
            clones[curr]->neighbors.push_back(clones[n]);
        }
    }
    return clone;
}
