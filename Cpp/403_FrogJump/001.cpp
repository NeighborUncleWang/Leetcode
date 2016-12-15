class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.empty()) return true;
        unordered_map<int, unordered_set<int>> map;
        for (int stone : stones) {
            map[stone] = unordered_set<int>();
        }
        map[0].insert(1);
        for (int i = 0; i < (int)stones.size() - 1; ++i) {
            int stone = stones[i];
            for (int step : map[stone]) {
                int reach = stone + step;
                if (reach == stones.back()) {
                    return true;
                } else if (map.count(reach)) {
                    map[reach].insert(step);
                    map[reach].insert(step + 1);
                    if (step > 1) {
                        map[reach].insert(step - 1);
                    }
                }
            }
        }
        return false;
    }
};