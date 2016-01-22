class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> table(256, 0);
        int oddCount = 0;
        for (char ch : s) {
            if (++table[ch] % 2) {
                ++oddCount;
            } else {
                --oddCount;
            }
        }
        return oddCount <= 1;
    }
};