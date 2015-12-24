class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>{0};
        vector<vector<int>> adjacentList(n);
        vector<int> degree(n, 0);
        for (auto edge : edges) {
            adjacentList[edge.first].push_back(edge.second);
            adjacentList[edge.second].push_back(edge.first);
            ++degree[edge.first];
            ++degree[edge.second];
        }
        vector<int> leaves;
        for (int i = 0; i < n; ++i) {
            if (degree[i] == 1) {
                leaves.push_back(i);
            }
        }
        vector<int> newLeaves;
        while (n > 2) {
            int leavesSize = leaves.size();
            n -= leavesSize;
            newLeaves.clear();
            for (int leaf : leaves) {
                for (int i : adjacentList[leaf]) {
                    if (--degree[i] == 1) {
                        newLeaves.push_back(i);
                    }
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};