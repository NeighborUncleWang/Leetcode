class Solution {
public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        if (points.empty()) return 0;
        sort(points.begin(), points.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.second < b.second;
        });
        int end = INT_MIN, result = 0;
        for (auto point : points) {
            if (point.first > end || end == INT_MIN) {
                ++result;
                end = point.second;
            }
        }
        return result;
    }
};