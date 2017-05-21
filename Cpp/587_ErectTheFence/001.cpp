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
private:
    int crossProduct(Point A, Point O, Point B) {
        return (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
    }
public:
    vector<Point> outerTrees(vector<Point>& points) {
        int n = points.size();
        auto comp = [](Point lhs, Point rhs) {
            return lhs.x < rhs.x || lhs.x == rhs.x && lhs.y < rhs.y;
        };
        vector<Point> res;
        //其实如果可以修改Point的类的话加上operator==然后提供一个hash function
        //就可以用unordered_set而不是set了
        set<Point, decltype(comp)> temp(comp);
        sort(points.begin(), points.end(), comp);
        for (int i = 0; i < n; ++i) {
            //crossProduct(res[res.size() - 2], res.back(), points[i])写>还是<0无所谓，
            //只要两个for-loop一致就行了
            //这就是MonotoneChain这个算法名字的由来
            //如果不考虑把共线的点加到conve hull里，那么要写成>=或者<=0
            while (res.size() >= 2 && crossProduct(res[res.size() - 2], res.back(), points[i]) > 0) {
                res.pop_back();
            }
            res.push_back(points[i]);
        }
        for (int i = n - 2, t = res.size() + 1; i >= 0; --i) {
            while (res.size() >= t && crossProduct(res[res.size() - 2], res.back(), points[i]) > 0) {
                res.pop_back();
            }
            res.push_back(points[i]);
        }
        for (auto it : res) {
            temp.insert(it);
        }
        return vector<Point>(temp.begin(), temp.end());
    }
};