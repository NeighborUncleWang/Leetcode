class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result(1 << n);
        iota(result.begin(), result.end(), 0);
        for_each(result.begin(), result.end(), [](int& num) { num ^= (num >> 1); });
        return result;
    }
};