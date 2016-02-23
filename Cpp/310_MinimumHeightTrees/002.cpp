class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return vector<int>{0}; 
        vector<vector<int>> adjList(n);
        vector<int> degrees(n, 0);
        for (auto& edge : edges) {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);
            ++degrees[edge.first];
            ++degrees[edge.second];
        }
        queue<int> nodesQueue;
        for (int i = 0; i < n; ++i) {
            if (degrees[i] == 1) {
                nodesQueue.push(i);
            }
        }
        while (n > 2) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                auto node = nodesQueue.front();
                nodesQueue.pop();
                for (int neighbor : adjList[node]) {
                    if (--degrees[neighbor] == 1) {
                        nodesQueue.push(neighbor);
                    }
                }
                --n;
            }
        }
        vector<int> result;
        int size = nodesQueue.size();
        for (int i = 0; i < size; ++i) {
            result.push_back(nodesQueue.front());
            nodesQueue.pop();
        }
        return result;
    }
};