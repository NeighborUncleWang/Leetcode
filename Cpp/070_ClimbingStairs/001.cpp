class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        int twoStepsBefore = 1;
        int oneStepBefore = 2;
        int result = 0;
        for (int i = 3; i <= n; ++i) {
            result = twoStepsBefore + oneStepBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = result;
        }
        return result;
    }
};