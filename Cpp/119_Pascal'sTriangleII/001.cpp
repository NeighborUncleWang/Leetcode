class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        for (int i = 0; i < rowIndex + 1; ++i) {
            for (int j = i - 1; j > 0; --j) {
                //可以写成result[j] += result[j - 1];
                result[j] = result[j] + result[j - 1];
            }
        }
        return result;
    }
};