class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int k = s3.size();
        if (m + n != k) {
            return false;
        }
        vector<vector<bool>> matrix(m + 1, vector<bool>(n + 1, false));
        matrix[0][0] = true;
        for (int j = 1; j < n + 1; ++j) {
            matrix[0][j] = s2[j - 1] == s3[j - 1] && matrix[0][j - 1];
        }//initialize the first row
        for (int i = 1; i < m + 1; ++i) {
            matrix[i][0] = s1[i - 1] == s3[i - 1] && matrix[i - 1][0];
        }//initialize the first column
        for (int i = 1; i < m + 1; ++i) {
            for (int j = 1; j < n + 1; ++j) {
                matrix[i][j] = matrix[i - 1][j] && s1[i - 1] == s3[i - 1 + j]
                || matrix[i][j - 1] && s2[j - 1] == s3[i - 1 + j];
            }
        }
        return matrix[m][n];
    }
};
