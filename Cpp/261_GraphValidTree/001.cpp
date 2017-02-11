class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int> weight(n, 1);
        vector<int> id(n, 0);
        iota(id.begin(), id.end(), 0);
        for (auto edge : edges) {
            int root1 = getRoot(edge.first, id);
            int root2 = getRoot(edge.second, id);
            if (root1 == root2) return false;
            if (weight[root1] < weight[root2]) {
                id[root1] = root2;
                weight[root2] += weight[root2];
            } else {
                id[root2] = root1;
                weight[root1] += weight[root2];
            }
        }
        return n == edges.size() + 1;
    }
private:
    int getRoot(int index, vector<int>& id) {
        while (index != id[index]) {
            id[index] = id[id[index]];
            index = id[index];
        }
        return index;
    }
};