class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> vowel{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int left = 0, right = (int)s.size() - 1;
        while (left < right) {
            while (left < right && !vowel.count(s[left])) {
                ++left;
            }
            while (left < right && !vowel.count(s[right])) {
                --right;
            }
            swap(s[left++], s[right--]);
        }
        return s;
    }
};