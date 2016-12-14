class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        int result = INT_MIN;
        for (int left = 0; left < column; ++left) {
            vector<int> sum_rows(row, 0);
            for (int right = left; right < column; ++right) {
                for (int i = 0; i < row; ++i) {
                    sum_rows[i] += matrix[i][right];
                }
                set<int> accumulates{0};
                int accumulate = 0;
                for (int i = 0; i < row; ++i) {
                    accumulate += sum_rows[i];
                    auto it = accumulates.lower_bound(accumulate - k);
                    if (it != accumulates.end()) {
                        result = max(result, accumulate - *it);
                    }
                    accumulates.insert(accumulate);
                }
            }
        }
        return result;
    }
};