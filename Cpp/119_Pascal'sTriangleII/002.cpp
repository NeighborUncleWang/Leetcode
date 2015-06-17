class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1);
        for (int i = 0; i <= rowIndex; ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == i) {
                    result[j] = 1;
                } else if (j == 0) {
                    result[j] = 1;
                } else {
                    result[j] = result[j] + result[j - 1];
                }
            }
        }
        return result;
    }
};
