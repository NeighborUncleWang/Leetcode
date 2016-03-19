class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int columnSize = rowSize == 0 ? 0 : grid[0].size();
        vector<int> rows(rowSize, 0);
        vector<int> columns(columnSize, 0);
        for (int i = 0; i < rowSize; ++i) {
            for (int j = 0; j < columnSize; ++j) {
                rows[i] += grid[i][j];
                columns[j] += grid[i][j];
            }
        }
        return getDistance1D(rows) + getDistance1D(columns);
    }
private:
    int getDistance1D(vector<int>& position) {
        int i = -1;
        int j = position.size();
        int left = 0;
        int right = 0;
        int distance = 0;
        //这里因为是先distance += left
        //再left += position[++i]
        //所以最后还得再加一轮
        //因为当i < j时其实poistion里的所有index都已经遍历过了
        //最后退出的时候i == j
        while (i < j) {
            if (left < right) {
                //如果下面两个statements互换位置应该怎么调整函数才能得到正确结果？
                distance += left;
                left += position[++i];
            } else {
                distance += right;
                right += position[--j];
            }
        }
        return distance;
    }
};