class Solution {
public:
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        long long pre = 0, cur = 0;
        for (int i = 0; i < n; ++i) {
            int dx1 = points[(i + 1) % n][0] - points[i][0];
            int dy1 = points[(i + 1) % n][1] - points[i][1];
            int dx2 = points[(i + 2) % n][0] - points[i][0];
            int dy2 = points[(i + 2) % n][1] - points[i][1];
            cur = dx1 * dy2 - dx2 * dy1;
            // 也可以写成这样
            // int OAx = points[i][0] - points[(i + 1) % n][0];
            // int OAy = points[i][1] - points[(i + 1) % n][1];
            // int OBx = points[(i + 2) % n][0] - points[(i + 1) % n][0];
            // int OBy = points[(i + 2) % n][1] - points[(i + 1) % n][1];
            // long long cur = OAx * OBy - OAy * OBx;
            //不能写成:
            //if (cur * pre < 0) {
            //    return false
            //} else {
            //    pre = cur;
            //}
            //否则一条线段由三个点组成的case通不过
            //cur会变成0, cur * pre == 0
            if (cur) {
                if (pre * cur < 0) {
                    return false;
                } else {
                    pre = cur;
                }
            }
        }
        return true;
    }
};