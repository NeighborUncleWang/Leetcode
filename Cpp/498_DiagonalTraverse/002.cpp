class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = row ? matrix[0].size() : 0;
        bool tag = true;
        vector<int> res;
        for (int index = 0; index < row + col - 1; ++index) {
            if (tag) {
                for (int i = min(row - 1, index); i >= max(0, index + 1 - col); --i) {
                    res.push_back(matrix[i][index - i]);
                }
            } else {
                for (int i = max(0, index + 1 - col); i <= min(row - 1, index); ++i) {
                    res.push_back(matrix[i][index - i]);
                }
            }
            tag = !tag;
        }
        return res;
    }
};