class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int row = picture.size(), col = row ? picture[0].size() : 0;
        vector<int> cols(col, 0);
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                   ++cols[j]; 
                }
            }
        }
        int res = 0;
        for (int i = 0; i < row; ++i) {
            int count = 0, index = 0;
            for (int j = 0; j < col; ++j) {
                if (picture[i][j] == 'B') {
                    ++count;
                    index = j;
                }
            }
            if (count == 1 && cols[index] == 1) ++res;
        }
        return res;
    }
};