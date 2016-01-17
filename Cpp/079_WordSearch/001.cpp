class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        int columnSize = rowSize == 0 ? 0 : board[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (dfs(board, word, rowSize, columnSize, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string& word, int rowSize, int columnSize,
    vector<vector<bool>>& visited, int i, int j, int index) {
        if (index == word.size()) {
            return true;
        }
        if (i < 0 || i >= rowSize || j < 0 || j >= columnSize
        || board[i][j] != word[index] || visited[i][j] == true) {
            return false;
        }
        visited[i][j] = true;
        bool result;
        if (dfs(board, word, rowSize, columnSize, visited, i, j - 1, index + 1)
        || dfs(board, word, rowSize, columnSize, visited, i, j + 1, index + 1)
        || dfs(board, word, rowSize, columnSize, visited, i - 1, j, index + 1)
        || dfs(board, word, rowSize, columnSize, visited, i + 1, j, index + 1)) {
            //如果返回值为true，就不用把visited[i][j]复原了
            //因为函数到这里开始回溯就结束了
            return true;
        } else {
            visited[i][j] = false;
            return false;
        }
    }
};