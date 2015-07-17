class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        vector<vector<int>> matrix(size1 + 1, vector<int>(size2 + 1, 0));
        for (int i = 0; i < size1 + 1; ++i) {
            matrix[i][0] = i;
        }
        for (int i = 0; i < size2 + 1; ++i) {
            matrix[0][i] = i;
        }
        for (int i = 1; i < size1 + 1; ++i) {
            for (int j = 1; j < size2 + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    matrix[i][j] = matrix[i - 1][j - 1];
                } else {
                    matrix[i][j] = min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]) + 1;
                }
            }
        }
        return matrix[size1][size2];
    }
};
