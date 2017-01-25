class Solution {
public:
    vector<int> findPermutation(string s) {
        vector<int> nums(s.size() + 1);
        iota(nums.begin(), nums.end(), 1);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'D') {
                int j = i;
                while (i < s.size() && s[i] == 'D') ++i;
                reverse(nums.begin() + j, nums.begin() + i + 1);
            }
        }
        return nums;
    }
};