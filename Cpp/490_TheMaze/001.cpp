class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = row ? maze[0].size() : 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        q.emplace(start[0], start[1]);
        visited[start[0]][start[1]] = true;
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            for (auto direction : directions) {
                int ii = current.first;
                int jj = current.second;
                while (ii >= 0 && ii < row && jj >= 0 && jj < col && maze[ii][jj] == 0) {
                    ii += direction.first;
                    jj += direction.second;
                }
                //go back to valid
                ii -= direction.first;
                jj -= direction.second;
                if (!visited[ii][jj]) {
                    if (ii == destination[0] && jj == destination[1]) return true;
                    q.emplace(ii, jj);
                    visited[ii][jj] = true;
                }
            }
        }
        return false;
    }
};