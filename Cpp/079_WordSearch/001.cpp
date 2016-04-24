class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        int columnSize = rowSize == 0 ? 0 : board[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (dfs(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word,
    vector<vector<bool>>& visited, int i, int j, int index) {
        if (index == word.size()) {
            return true;
        }
        //这题必须要在递归刚进来的时候再检查i,j是否在边界内
        //否则["A"], "A"这种case过不了
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
        || board[i][j] != word[index] || visited[i][j]) {
            return false;
        }
        visited[i][j] = true;
        bool result;
        //不过i+1,i-1,j+1,j-1是否在边界内，都要调用dfs函数
        //这样才能让index+1顺利到达word.size()
        //这题和其他在矩阵里找路径的题目的解法不同
        if (dfs(board, word, visited, i, j - 1, index + 1)
        || dfs(board, word, visited, i, j + 1, index + 1)
        || dfs(board, word, visited, i - 1, j, index + 1)
        || dfs(board, word, visited, i + 1, j, index + 1)) {
            return true;
        } else {
            visited[i][j] = false;
            return false;
        }
    }
};