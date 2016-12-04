class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int booms = 0;
        for (auto p : points) {
            //gives the map an initial size can make the program faster
            unordered_map<double, int> map(points.size());
            for (auto q : points) {
                booms += 2 * map[hypot(p.first - q.first, p.second - q.second)]++;
            }
        }
        return booms;
    }
};