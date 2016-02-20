class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        if (n != edges.size() + 1) {
            return false;
        }
        UnionFind unionFind(n);
        for (auto& edge : edges) {
            unionFind.unite(edge.first, edge.second);
        }
        return unionFind.count == 1;
    }
private:
    struct UnionFind {
        int count;
        vector<int> roots;
        vector<int> weights;
        UnionFind(int n) {
            roots = vector<int>(n, 0);
            iota(roots.begin(), roots.end(), 0);
            weights = vector<int>(n, 1);
            count = n;
        }
        int getRoot(int node) {
            while (roots[node] != node) {
                roots[node] = roots[roots[node]];
                node = roots[node];
            }
            return node;
        }
        void unite(int left, int right) {
            int leftRoot = getRoot(left);
            int rightRoot = getRoot(right);
            if (weights[leftRoot] < weights[rightRoot]) {
                roots[leftRoot] = rightRoot;
                weights[rightRoot] += weights[leftRoot];
            } else {
                roots[rightRoot] = leftRoot;
                weights[leftRoot] += weights[rightRoot];
            }
            --count;
        }
    };
};