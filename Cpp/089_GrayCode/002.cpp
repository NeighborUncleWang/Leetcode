class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        result.push_back(0);
        if (n == 0) {
            return result;
        }
        result.push_back(1);
        for (int i = 1; i <= n - 1; ++i) {
            int highestBit = 1 << i;
            int size = result.size();
            for (int j = size - 1; j >= 0; --j) {
                result.push_back(highestBit + result[j]);
            }
        }
        return result;
    }
};
