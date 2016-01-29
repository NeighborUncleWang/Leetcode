class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) {
            word1.swap(word2);
        }
        int row = word1.size() + 1;
        int column = word2.size() + 1;
        vector<int> previousRow(column, 0);
        for (int i = 0; i < column; ++i) {
            previousRow[i] = i;
        }
        vector<int> currentRow(column, 0);
        for (int i = 1; i < row; ++i) {
            currentRow[0] = i;
            for (int j = 1; j < column; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    currentRow[j] = previousRow[j - 1];
                } else {
                    currentRow[j] = min({previousRow[j - 1], previousRow[j], currentRow[j - 1]}) + 1;
                }
            }
            previousRow = currentRow;
        }
        return currentRow.back();
    }
};
