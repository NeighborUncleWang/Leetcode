class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        UnionFind components(n);
        for (auto& edge : edges) {
            components.unite(edge.first, edge.second);
        }
        return components.count;
    }
private:
    struct UnionFind {
        vector<int> root;
        vector<int> size;
        int count;
        UnionFind(int n) : size(n, 1), count(n) {
            root = vector<int>(n, 0);
            for (int i = 0; i < n; ++i) {
                root[i] = i;
            }
        }
        int getRoot(int index) {
            while (root[index] != index) {
                root[index] = root[root[index]];
                index = root[index];
            }
            return index;
        }
        void unite(int left, int right) {
            int rootLeft = getRoot(left);
            int rootRight = getRoot(right);
            if (rootLeft == rootRight) return;
            if (size[rootLeft] < size[rootRight]) {
                root[rootLeft] = rootRight;
                size[rootRight] += size[rootLeft];
            } else {
                root[rootRight] = rootLeft;
                size[rootLeft] += size[rootRight];
            }
            --count;
        }
    };
};