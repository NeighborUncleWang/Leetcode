class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        auto row = board.size();
        auto column = board[0].size();
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        for (auto i = 0; i < row; ++i) {
            for (auto j = 0; j < column; ++j) {
                if (DFS(board, word, visited, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    bool DFS(vector<vector<char>>& board, string word,
    vector<vector<bool>>& visited, int i, int j, int k) {
        if (k == word.size()) {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
        || board[i][j] != word[k] || visited[i][j] == true) {
            return false;
        }
        visited[i][j] = true;
        bool result;
        if (DFS(board, word, visited, i, j - 1, k + 1)
        || DFS(board, word, visited, i, j + 1, k + 1)
        || DFS(board, word, visited, i - 1, j, k + 1)
        || DFS(board, word, visited, i + 1, j, k + 1)) {
            result = true;
        } else {
            result = false;
        }
        visited[i][j] = false;
        return result;
    }
};
