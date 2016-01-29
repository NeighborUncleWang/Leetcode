class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size() < word2.size()) {
            word1.swap(word2);
        }
        vector<int> row(word2.size() + 1, 0);
        for (int i = 0; i < row.size(); ++i) {
            row[i] = i;
        }
        vector<int> nextRow(word2.size() + 1, 0);
        for (int i = 1; i < word1.size() + 1; ++i) {
            nextRow[0] = i;
            for (int j = 1; j < word2.size() + 1; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    nextRow[j] = row[j - 1];//remember to assign row[j - 1] instead of row[j]
                } else {
                    nextRow[j] = min({row[j - 1], row[j], nextRow[j - 1]}) + 1;
                }
            }
            row = nextRow;
        }
        return nextRow.back();
    }
};
