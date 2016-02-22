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
        if (node == nullptr) {
            return nullptr;
        }
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> nodesMap;
        return dfs(node, nodesMap);
    }
private:
    UndirectedGraphNode* dfs(UndirectedGraphNode* node,
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& nodesMap) {
        UndirectedGraphNode* copyNode = new UndirectedGraphNode(node->label);
        nodesMap[node] = copyNode;
        for (auto neighbor : node->neighbors) {
            //this equals to status[neighbor] == UNKNOWN
            if (nodesMap.find(neighbor) == nodesMap.end()) {
                copyNode->neighbors.push_back(dfs(neighbor, nodesMap));
            } else {
                copyNode->neighbors.push_back(nodesMap[neighbor]);
            }
        }
        return copyNode;
    }
};