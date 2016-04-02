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
        if (node == nullptr) return nullptr;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodesMap;
        dfs(node, nodesMap);
        return nodesMap[node];
    }
private:
    void dfs(UndirectedGraphNode* node,
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodesMap) {
        nodesMap[node] = new UndirectedGraphNode(node->label);
        for (auto neighbor : node->neighbors) {
            //this equals to status[neighbor] == UNKNOWN
            if (nodesMap.find(neighbor) == nodesMap.end()) {
                dfs(neighbor, nodesMap);
            }
            nodesMap[node]->neighbors.push_back(nodesMap[neighbor]);
        }
    }
};