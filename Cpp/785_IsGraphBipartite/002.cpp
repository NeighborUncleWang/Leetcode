class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.empty()) return false;
        int n = graph.size();
        unordered_map<int, bool> colors;
        for (int i = 0; i < n; ++i) {
            if (colors.find(i) == colors.end() && !valid_color(graph, true, colors, i)) {
                return false;
            }
        }
        return true;
    }
private:
    bool valid_color(vector<vector<int>>& graph, bool color, unordered_map<int, bool>& colors, int cur) {
        colors[cur] = color;
        for (int neighbor : graph[cur]) {
            if (colors.find(neighbor) == colors.end() && !valid_color(graph, !color, colors, neighbor)) {
                return false;
            } else if (colors[neighbor] == colors[cur]) {
                return false;
            }
        }
        return true;
    }
};
