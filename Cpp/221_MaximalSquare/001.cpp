class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        vector<int> current(columnSize + 1, 0);
        vector<int> previous(columnSize + 1, 0);
        int maxLength = 0;
        for (int i = 1; i <= rowSize; ++i) {
            for (int j = 1; j <= columnSize; ++j) {
                if (matrix[i - 1][j - 1] == '0') {
                    current[j] = 0;
                } else {
                    current[j] = min({current[j - 1], previous[j - 1], previous[j]}) + 1;
                }
                maxLength = max(maxLength, current[j]);
            }
            previous = current;
        }
        return maxLength * maxLength;
    }
};