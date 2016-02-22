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
        queue<UndirectedGraphNode*> nodesQueue;
        nodesQueue.push(node);
        nodesMap[node] = new UndirectedGraphNode(node->label);
        while (!nodesQueue.empty()) {
            auto current = nodesQueue.front();
            nodesQueue.pop();
            for (auto neighbor : current->neighbors) {
                //this equals to status[neighbor] = UNKNOWN
                if (nodesMap.find(neighbor) == nodesMap.end()) {
                    nodesQueue.push(neighbor);
                    nodesMap[neighbor] = new UndirectedGraphNode(neighbor->label);
                }
                nodesMap[current]->neighbors.push_back(nodesMap[neighbor]);
            }
        }
        return nodesMap[node];
    }
};