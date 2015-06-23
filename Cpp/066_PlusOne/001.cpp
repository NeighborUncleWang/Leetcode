class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        auto n = digits.size();
        vector<int> result(n);
        for (int i = n - 1; i >= 0; --i) {
            result[i] = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
        }
        if (carry) {
            result.insert(result.begin(), 1);
        }
        return result;
    }
};
