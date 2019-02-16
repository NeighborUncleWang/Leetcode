class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> weights(n + 1, 1);
        vector<int> roots(n + 1, 0);
        iota(roots.begin() + 1, roots.end(), 1);
        for (auto& edge : edges) {
            int root1 = findRoot(edge[0], roots);
            int root2 = findRoot(edge[1], roots);
            if (root1 == root2) {
                return edge;
            } else {
                if (weights[root1] < weights[root2]) {
                    roots[root1] = root2;
                    weights[root2] += weights[root1];
                } else {
                    roots[root2] = root1;
                    weights[root1] += weights[root2];
                }
            }
        }
        return vector<int>();
    }
private:
    int findRoot(int index, vector<int>& roots) {
        while (index != roots[index]) {
            roots[index] = roots[roots[index]];
            index = roots[index];
        }
        return index;
    }
};
