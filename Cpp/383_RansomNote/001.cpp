class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash_map(26, 0);
        for (char ch : magazine) {
            ++hash_map[ch - 'a'];
        }
        for (char ch : ransomNote) {
            if (hash_map[ch - 'a']-- == 0) {
                return false;
            }
        }
        return true;
    }
};