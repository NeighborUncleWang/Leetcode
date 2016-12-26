class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        unordered_map<int, unordered_set<int>> map;
        int min_x = INT_MAX, max_x = INT_MIN;
        for (auto point : points) {
            min_x = min(min_x, point.first);
            max_x = max(max_x, point.first);
            map[point.second].insert(point.first);
        }
        int sum = min_x + max_x;
        for (auto& it : map) {
            for (int x : it.second) {
                if (2 * x != sum) {
                    if (it.second.count(sum - x) == 0) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};