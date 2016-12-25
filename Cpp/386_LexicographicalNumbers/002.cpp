class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            dfs(i, n, result);
        }
        return result;
    }
private:
    void dfs(int current, int n, vector<int>& result) {
        if (current <= n) {
            result.push_back(current);
            for (int i = 0; i <= 9; ++i) {
                dfs(current * 10 + i, n, result);
            }
        }
    }
};