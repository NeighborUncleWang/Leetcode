class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> hash_map;
        for (char ch : s) {
            ++hash_map[ch];
        }
        int odd = 0;
        for (auto it = hash_map.begin(); it != hash_map.end(); ++it) {
            if (it->second % 2) {
                ++odd;
            }
        }
        return s.size() - odd + (odd > 0);
    }
};