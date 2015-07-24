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
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hashMap;
        queue<UndirectedGraphNode*> nodesQueue;
        auto source = new UndirectedGraphNode(node->label);
        nodesQueue.push(node);
        hashMap[node] = source;
        while (nodesQueue.empty() == false) {
            auto graphNode = nodesQueue.front();
            nodesQueue.pop();
            for (auto i : graphNode->neighbors) {
				//this equals to state[i] == UNKNOWN
                if (hashMap.find(i) == hashMap.end()) {
                    auto newNode = new UndirectedGraphNode(i->label);
                    hashMap[i] = newNode;
                    nodesQueue.push(i);
                }
                hashMap[graphNode]->neighbors.push_back(hashMap[i]);
            }
        }
        return source;
    }
};
