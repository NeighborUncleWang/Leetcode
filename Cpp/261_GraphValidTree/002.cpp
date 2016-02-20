class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        //其实dfs不用判断cycle，直接最开始判断n == edges.size() + 1就行
        vector<vector<int>> adjList(n, vector<int>());
        for (auto& edge : edges) {
            adjList[edge.first].push_back(edge.second);
            adjList[edge.second].push_back(edge.first);
        }
        int visitedNodes = 0;
        vector<bool> unknown(n, true);
        if (dfsCycle(0, unknown, adjList, visitedNodes, -1)) {
            return false;
        }
        return visitedNodes == n;
    }
private:
    bool dfsCycle(int node, vector<bool>& unknown, vector<vector<int>>&adjList, int& visitedNodes, int parent) {
        ++visitedNodes;
        unknown[node] = false;
        for (int i : adjList[node]) {
            if (unknown[i]) {
                //这里不能写成unknown[i] && dfsCycle(i, unknown, adjList, visitedNodes, node)
                //因为有可能出现dfsCycle()返回false，然后进入else if (i != partent)判断，
                //这样的话会导致出错
                if (dfsCycle(i, unknown, adjList, visitedNodes, node)) return true;
            } else if (i != parent) {
                return true;
            }
        }
        return false;
    }
};