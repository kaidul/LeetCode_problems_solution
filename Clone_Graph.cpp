/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return node;
        unordered_map <UndirectedGraphNode*, UndirectedGraphNode*> visited;
        UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
        visited[node] = newNode;
        queue <UndirectedGraphNode*> Q;
        Q.push(node);
        while(!Q.empty()) {
            UndirectedGraphNode *curr = Q.front();
            Q.pop();
            UndirectedGraphNode *u, *v;
            for(int i = 0, n = (int)curr->neighbors.size(); i < n; ++i) {
                u = visited[curr];
                v = curr->neighbors[i];
                if(!visited[v]) {
                    UndirectedGraphNode *neigh = new UndirectedGraphNode(v->label);
                    visited[v] = neigh;
                    u->neighbors.push_back(neigh);
                    Q.push(v);
                } else {
                    u->neighbors.push_back(visited[v]);
                }
            }
        }
        return newNode;
    }
};