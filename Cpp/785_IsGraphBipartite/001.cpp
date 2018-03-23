class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty()) return false;
        int n = graph.size();
        unordered_map<int, bool> colors;
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (colors.find(i) == colors.end()) {
                q.push(i);
                while (!q.empty()) {
                    int cur = q.front();
                    q.pop();
                    for (int neighbor : graph[cur]) {
                        if (colors.find(neighbor) == colors.end()) {
                            colors[neighbor] = !colors[cur];
                            q.push(neighbor);
                        } else if (colors[neighbor] == colors[cur]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
