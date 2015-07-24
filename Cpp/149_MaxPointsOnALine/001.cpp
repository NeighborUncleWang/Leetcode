/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> hashMap;
        //当points.size() == 1时，下面的for loop不会执行，所以这里maxNumber = 1保证函数最后还能返回1
        int maxNumber = 1;
        if (points.size() == 0) {
            return 0;
        }
        //必须单独考虑points.size() == 0情况，否则下面points.size() - 1返回的不是-1而是size_t::max，导致死循环
        //另一种方法是i < (int)points.size()
        for (int i = 0; i < points.size() - 1; ++i) {
            int duplicate = 1;
            double slope = 0.0;
            hashMap.clear();
            //这里是考虑所有点都是duplicate的情况，如果不加入这一项会导致hashMap为空，后面计算maxNumber的for loop也无法执行，从而出错，另一种方法是设一个localMax
            hashMap[numeric_limits<double>::lowest()] = 0;
            for (int j = i + 1; j < points.size(); ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    ++duplicate;
                } else {
                    if (points[i].x == points[j].x) {
                        slope = numeric_limits<double>::max();
                    } else {
                        slope = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
                    }
                    ++hashMap[slope];
                }
            }
            for (auto it : hashMap) {
                maxNumber = max(maxNumber, it.second + duplicate);
            }
        }
        return maxNumber;
    }
};
