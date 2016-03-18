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
        int size = points.size();
        if (size == 0) return 0;
        unordered_map<double, int> hashMap;
        //当points.size() == 1时，下面的for loop不会执行，所以这里maxPoints = 1保证函数最后还能返回1
        int maxPoints = 1;
        for (int i = 0; i < size - 1; ++i) {
            //我一开始写的时候没有写hashMap.clear()
            //相当于把所有的可能的pair都存到同一个hashMap里了
            //这样会有很多重复
            //但是我也不是很懂为什么每次清空hashMap就是正确的
            //因为一个固定经过的点和斜率决定一系列直线，如果两条线平行只按斜率来存到hashMap里明显就不对了
            //但是这个方法还是有很多重复计算，比如所有点都不相同然后都共线，
            //那么其实只要outer loop执行一次就得到正确结果了，但是这里还是会让outer loop执行size - 1次
            hashMap.clear();
            int duplicates = 1;
            int localMax = 0;
            //这里是考虑所有点都是duplicate的情况，如果不加入这一项会导致hashMap为空，
            //后面计算maxNumber的for loop也无法执行，从而出错，另一种方法是设一个localMax
            for (int j = i + 1; j < size; ++j) {
                if (points[i].x == points[j].x && points[i].y == points[j].y) {
                    //这里要考虑duplicates
                    ++duplicates;
                } else {
                    double slope;
                    if (points[i].x == points[j].x) {
                        slope = numeric_limits<double>::max();
                    } else {
                        slope = (points[i].y - points[j].y) * 1.0 / (points[i].x - points[j].x);
                    }
                    ++hashMap[slope];
                }
            }
            for (auto& iter : hashMap) {
                localMax = max(localMax, iter.second);
            }
            maxPoints = max(maxPoints, localMax + duplicates);
        }
        return maxPoints;
    }
};