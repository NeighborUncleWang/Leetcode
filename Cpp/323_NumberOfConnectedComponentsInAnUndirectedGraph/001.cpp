class Solution {
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> weight(n, 1);
        vector<int> id(n, 0);
        iota(id.begin(), id.end(), 0);
        for (auto edge : edges) {
            int id1 = getId(edge.first, id);
            int id2 = getId(edge.second, id);
            if (id1 != id2) {
                if (weight[id1] < weight[id2]) {
                    id[id1] = id2;
                    weight[id2] += weight[id1];
                } else {
                    id[id2] = id1;
                    weight[id1] += weight[id2];
                }
                --n;
            }
        }
        return n;
    }
private:
    int getId(int index, vector<int>& id) {
        while (index != id[index]) {
            id[index] = id[id[index]];
            index = id[index];
        }
        return index;
    }
};