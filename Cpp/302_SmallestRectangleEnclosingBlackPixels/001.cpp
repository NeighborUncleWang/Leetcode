class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int rowSize = image.size();
        int columnSize = rowSize ? image[0].size() : 0;
        //top means the smaller row index boundary
        //这里选了[0, x]两个肯定都在边界里的值，更保险一点
        int smallRowIndex = searchRow(image, 0, x, 0, columnSize, true);
        int largeRowIndex = searchRow(image, x, rowSize - 1, 0, columnSize, false);
        int smallColumnIndex = searchColumn(image, 0, y, 0, rowSize, true);
        int largeColumnIndex = searchColumn(image, y, columnSize - 1, 0, rowSize, false);
        return (largeRowIndex - smallRowIndex) * (largeColumnIndex - smallColumnIndex);
    }
private:
    int searchRow(vector<vector<char>>& image, int smallRow, int largeRow, 
    int smallColumn, int largeColumn, bool tag) {
        while (smallRow <= largeRow) {
            int midRow = smallRow + (largeRow - smallRow) / 2;
            int k = 0;
            while (k < largeColumn && image[midRow][k] == '0') ++k;
            if (k < largeColumn == tag) {
                largeRow = midRow - 1;
            } else {
                smallRow = midRow + 1;
            }
        }
        return smallRow;
    }
    int searchColumn(vector<vector<char>>& image, int smallColumn, int largeColumn,
    int smallRow, int largeRow, bool tag) {
        while (smallColumn <= largeColumn) {
            int midColumn = smallColumn + (largeColumn - smallColumn) / 2;
            int k = 0;
            while (k < largeRow && image[k][midColumn] == '0') ++k;
            if (k < largeRow == tag) {
                largeColumn = midColumn - 1;
            } else {
                smallColumn = midColumn + 1;
            }
        }
        return smallColumn;
    }
};