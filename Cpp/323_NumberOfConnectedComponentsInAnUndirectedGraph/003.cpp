class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adjacentList(n);
        for (auto& edge : edges) {
            adjacentList[edge.first].push_back(edge.second);
            adjacentList[edge.second].push_back(edge.first);
        }
        int count = 0;
        vector<bool> visited(n, false);
        queue<int> nodesQueue;
        for (int i = 0; i < n; ++i) {
            if (visited[i] == false) {
                ++count;
                nodesQueue.push(i);
                visited[i] = true;
                while (!nodesQueue.empty()) {
                    int node = nodesQueue.front();
                    nodesQueue.pop();
                    for (int neighbor : adjacentList[node]) {
                        if (!visited[neighbor]) {
                            nodesQueue.push(neighbor);
                            visited[neighbor] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};