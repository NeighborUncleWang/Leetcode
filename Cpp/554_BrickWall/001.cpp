class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> map;
        int count = 0;
        for (auto& row : wall) {
            int length = 0;
            for (int i = 0; i < row.size() - 1; ++i) {
                length += row[i];
                ++map[length];
                count = max(count, map[length]);
            }
        }
        return wall.size() - count;
    }
};