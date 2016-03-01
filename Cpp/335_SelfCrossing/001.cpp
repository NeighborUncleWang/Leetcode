class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int size = x.size();
        for (int i = 3; i < size; ++i) {
            //case1
            if (x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
            //case2
            if (i > 3 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
            //case3
            //这里我多加了x[i] <= x[i - 2]和x[i - 5] <= x[i - 3],这样确保是case3,否则有可能是case2
            //不过其实对结果没影响，因为如果满足case2在上一个if statement就return true了
            if (i > 4 && x[i - 4] <= x[i - 2] && x[i] <= x[i - 2] && x[i] + x[i - 4] >= x[i - 2]
            && x[i - 5] <= x[i - 3] && x[i - 1] <= x[i - 3] && x[i - 5] + x[i - 1] >= x[i - 3]) return true;
        }
        return false;
    }
};