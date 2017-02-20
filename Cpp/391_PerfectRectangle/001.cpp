class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        unordered_set<string> points;
        int x1 = INT_MAX, y1 = INT_MAX;
        int x2 = INT_MIN, y2 = INT_MIN;
        int area = 0;
        for (auto& rect : rectangles) {
            x1 = min(x1, rect[0]);
            y1 = min(y1, rect[1]);
            x2 = max(x2, rect[2]);
            y2 = max(y2, rect[3]);
            string p1 = to_string(rect[0]) + " " + to_string(rect[1]);
            string p2 = to_string(rect[0]) + " " + to_string(rect[3]);
            string p3 = to_string(rect[2]) + " " + to_string(rect[3]);
            string p4 = to_string(rect[2]) + " " + to_string(rect[1]);
            if (!points.insert(p1).second) points.erase(p1);
            if (!points.insert(p2).second) points.erase(p2);
            if (!points.insert(p3).second) points.erase(p3);
            if (!points.insert(p4).second) points.erase(p4);
            area += (rect[2] - rect[0]) * (rect[3] - rect[1]);
        }
        //不能只检查points.size() == 4
        //还要检查留下来的4个点是不是矩形最外面的4个点
        //否则[[0,0,1,1],[0,0,2,1],[1,0,2,1],[0,2,2,3]]case 过不去
        //最后要检查的是剩下的四个点是最边沿的四个点并且所围成的面积是之前所有矩形面积之和
        if (!points.count(to_string(x1) + " " + to_string(y1)) || !points.count(to_string(x2) + " " + to_string(y1)) ||
        !points.count(to_string(x1) + " " + to_string(y2)) || !points.count(to_string(x2) + " " + to_string(y2))) {
            return false;
        }
        return points.size() == 4 && (y2 - y1) * (x2 - x1) == area;
    }
};