class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        unordered_map<long long, int> distances;
        auto f = [](pair<int, int> lhs, pair<int, int> rhs) {
            return (long long)pow(lhs.first - rhs.first, 2) + (long long)pow(lhs.second - rhs.second, 2);
        };
        for (int i = 0; i < points.size(); ++i) {
            for (int j = 0; j < points.size(); ++j) {
                if (i == j) continue;
                distances[f(points[i], points[j])]++;
            }
            for (auto& it : distances) {
                res += it.second * (it.second - 1);
            }
            distances.clear();
        }
        return res;
    }
};