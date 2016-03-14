class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> matrix;
        for (int i = 0; i < numRows; ++i) {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                temp[j] = matrix[i - 1][j] + matrix[i - 1][j - 1];
            }
            matrix.push_back(move(temp));
        }
        return matrix;
    }
};