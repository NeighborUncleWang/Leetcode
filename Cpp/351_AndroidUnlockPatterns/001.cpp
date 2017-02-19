class Solution {
public:
    int numberOfPatterns(int m, int n) {
        vector<vector<int>> skip(10, vector<int>(10, 0));
        skip[1][3] = skip[3][1] = 2;
        skip[7][9] = skip[9][7] = 8;
        skip[1][7] = skip[7][1] = 4;
        skip[3][9] = skip[9][3] = 6;
        skip[1][9] = skip[9][1] = skip[2][8] = skip[8][2] = skip[3][7] = skip[7][3] = skip[4][6] = skip[6][4] = 5;
        int result = 0;
        vector<bool> visited(10, false);
        for (int i = m; i <= n; ++i) {
            result += dfs(skip, visited, 1, i - 1) * 4;
            result += dfs(skip, visited, 2, i - 1) * 4;
            result += dfs(skip, visited, 5, i - 1);
        }
        return result;
    }
private:
    int dfs(vector<vector<int>>& skip, vector<bool>& visited, int current, int remain) {
        if (remain == 0) return 1;
        visited[current] = true;
        int result = 0;
        for (int i = 1; i <= 9; ++i) {
            if (!visited[i] && (!skip[current][i] || visited[skip[current][i]])) {
                result += dfs(skip, visited, i, remain - 1);
            }
        }
        //这里不是真的dfs,只是寻找所有可能序列的个数
        //所以要把visited[current]设置回false
        //如果是dfs的话只会把所有节点都visit一遍就结束了
        visited[current] = false;
        return result;
    }
};