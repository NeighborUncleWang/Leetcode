class Solution {
public:
    bool canPermutePalindrome(string s) {
        //the size of a char is 1 byte on both 32-bit
        //and 64-bit platform
        bitset<256> b;
        for (auto ch : s) {
            b.flip(ch);
        }
        return b.count() < 2;
    }
};