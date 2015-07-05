class Solution {
public:
    string longestPalindrome(string s) {
        string::size_type n = s.size();
        vector<vector<bool>> palindromeMatrix(n, vector<bool>(n));
        int maxLength = 0;
        string result;
        for (int i = n - 1; i >= 0; --i) {//这里i必须从大到小，因为当前行的数据要借助矩阵下一行的数据才能得到
            for (int j = i; j < n; ++j) {//这里J可以从小到大也可以从到到小
                if (s[i] == s[j] && (j - i <= 2 || palindromeMatrix[i + 1][j - 1])) {
                    palindromeMatrix[i][j] = true;
                    if (j - i + 1 > maxLength) {
                        maxLength = j - i + 1;
                        result = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return result;
    }
};
