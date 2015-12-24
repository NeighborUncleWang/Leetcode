class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>{0};
        vector<unordered_set<int>> adjacentList(n);
        for (auto edge : edges) {
            adjacentList[edge.first].insert(edge.second);
            adjacentList[edge.second].insert(edge.first);
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (adjacentList[i].size() == 1) {
                leaves.push_back(i);
            }
        }
        vector<int> newLeaves;
        while (n > 2) {
            int leavesSize = leaves.size();
            n -= leavesSize;
            newLeaves.clear();
            for (int leaf : leaves) {
                int j = *adjacentList[leaf].begin();
                adjacentList[j].erase(leaf);
                if (adjacentList[j].size() == 1) newLeaves.push_back(j);
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};