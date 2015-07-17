class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        } else if (n == 2) {
            return 2;
        }
        vector<int> solution(n);
        solution[0] = 1;
        solution[1] = 2;
        for (int i = 2; i < solution.size(); ++i) {
            solution[i] = solution[i - 1] + solution[i - 2];
        }
        return solution.back();
    }
};
