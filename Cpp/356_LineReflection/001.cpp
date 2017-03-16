class Solution {
public:
    bool isReflected(vector<pair<int, int>>& points) {
        //这题重复的点只计算一次，比如[[-16,1],[16,1],[16,1]]
        //要返回true
        //如果要计算多次的话map就要改成unordered_map<int, unordered_map<int, int>>
        //把每个值出现的次数也计算进去
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
                    if (it.second.find(sum - x) == it.second.end()) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};