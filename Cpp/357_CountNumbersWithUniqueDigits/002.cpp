class Solution {
private:
    int dfs(vector<bool>& used, long long cur, long long max) {
        int count = 0;
        if (cur < max) {
            ++count;
        } else {
            return count;
        }
        for (int i = 0; i < 10; ++i) {
            if (!used[i]) {
                used[i] = true;
                count += dfs(used, cur * 10 + i, max);
                used[i] = false;
            }
        }
        return count;
    }
public:
    int countNumbersWithUniqueDigits(int n) {
        int res = 1;
        long long max = pow(10, n);
        vector<bool> used(10, false);
        for (int i = 1; i < 10; ++i) {
            used[i] = true;
            res += dfs(used, i, max);
            used[i] = false;
        }
        return res;
    }
};