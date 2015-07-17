class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        f1 = 1;
        f2 = 2;
        for (int i = 2; i < n; ++i) {
            int f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f2;
    }
};
