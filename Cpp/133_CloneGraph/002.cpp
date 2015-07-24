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
        DFS(node, hashMap);
        return hashMap[node];
    }
private:
    void DFS(UndirectedGraphNode* node, unordered_map<UndirectedGraphNode*, UndirectedGraphNode*>& hashMap) {
        auto newNode = new UndirectedGraphNode(node->label);
        hashMap[node] = newNode;//this equals state[node]<-DISCOVERED
        for (auto i : node->neighbors) {
            //this equals if (state[i] == UNKNOWN)
            if (hashMap.find(i) == hashMap.end()) {
                DFS(i, hashMap);
            }
            hashMap[node]->neighbors.push_back(hashMap[i]);
        }
    }
};
