class Solution {
private:
    int dfs(vector<bool>& used, int pos, int N) {
        if (pos == N + 1) {
            return 1;
        }
        int res = 0;
        for (int i = 1; i <= N; ++i) {
            if (!used[i] && (pos % i == 0 || i % pos == 0)) {
                used[i] = true;
                res += dfs(used, pos + 1, N);
                used[i] = false;
            }
        }
        return res;
    }
public:
    int countArrangement(int N) {
        vector<bool> used(N + 1, false);
        return dfs(used, 1 , N);
    }
};