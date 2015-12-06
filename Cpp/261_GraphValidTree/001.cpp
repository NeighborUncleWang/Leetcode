class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (edges.size() != n - 1) {
            return false;
        }
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        for (auto edge : edges) {
            int rootFirst = getRoot(parent, edge.first);
            int rootSecond = getRoot(parent, edge.second);
            if (rootFirst == rootSecond) {
                return false;
            } else {
                parent[rootFirst] = rootSecond; 
            }
        }
        return true;
    }
private:
    int getRoot(vector<int>& parent, int index) {
        while (parent[index] != index) {
            index = parent[index];
        }
        return index;
    }
};