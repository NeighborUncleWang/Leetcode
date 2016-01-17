class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rowSize = board.size();
        int columnSize = rowSize == 0 ? 0 : board[0].size();
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        vector<pair<int, int>> directions{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                if (dfs(board, word, 0, i, j, rowSize, columnSize, visited, directions)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool dfs(vector<vector<char>>& board, string& word, int index, int i, int j, 
    int rowSize, int columnSize, vector<vector<bool>>& visited, vector<pair<int, int>>& directions) {
        //这里必须提前判断
        //不能用index == word.size() return true
        //来作为结束条件，否则[['A']], A这个case就过不去了
        if (index == word.size() - 1 && word[index] == board[i][j]) {
            return true;
        } else if (word[index] != board[i][j]) {
            return false;
        }
        visited[i][j] = true;
        for (pair<int, int>& direction : directions) {
            int ii = i + direction.first;
            int jj = j + direction.second;
            if (ii >= 0 && ii < rowSize && jj >= 0 && jj < columnSize 
            && visited[ii][jj] == false) {
                if (dfs(board, word, index + 1, ii, jj, rowSize, columnSize, visited, directions)) {
                    return true;
                }
            }
        }
        visited[i][j] = false;
        return false;
    }
};