class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int carry = 1, sum = 0;
        for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
            if (*it == 9) {
                *it = 0;
            } else {
                *it += 1;
                return digits;
            }
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};