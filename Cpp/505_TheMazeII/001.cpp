class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int row = maze.size(), col = row ? maze[0].size() : 0;
        queue<pair<int, int>> q;
        vector<vector<int>> distance(row, vector<int>(col, INT_MAX));
        q.emplace(start[0], start[1]);
        distance[start[0]][start[1]] = 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto current = q.front();
            q.pop();
            for (auto direction : directions) {
                int ii = current.first;
                int jj = current.second;
                int level = 0;
                while (ii + direction.first >= 0 && ii + direction.first < row && 
                jj + direction.second >= 0 && jj + direction.second < col && 
                maze[ii + direction.first][jj + direction.second] == 0) {
                    ++level;
                    ii += direction.first;
                    jj += direction.second;
                }
                // 上面的代码也可以写成下面这样
                // int ii = cur.first + direction.first;
                // int jj = cur.second + direction.second;
                // int level = 1;
                // while (ii >= 0 && ii < row && jj >= 0 && jj < col && maze[ii][jj] == 0) {
                //     ++level;
                //     ii += direction.first;
                //     jj += direction.second;
                // }
                // --level;
                //如果distance[ii][jj] > distance[current.first][current.second] + level
                //说明有更短的路径到达当前位置，所以再visit一遍把以(ii,jj)为出发点之后的点都update一遍
                //这里必须这么写，如果写distance[ii][jj] == INT_MAX的话（只考虑第一次访问这个点的情况）会通不过OJ
                if (distance[ii][jj] > distance[current.first][current.second] + level) {
                    distance[ii][jj] = distance[current.first][current.second] + level;
                    q.emplace(ii, jj);
                }
            }
        }
        return distance[destination[0]][destination[1]] == INT_MAX ? -1 : distance[destination[0]][destination[1]];
    }
};