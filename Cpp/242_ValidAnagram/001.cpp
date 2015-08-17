class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> hashTable(26, 0);
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); ++i) {
            ++hashTable[s[i] - 'a'];
            --hashTable[t[i] - 'a'];
        }
        for (int i = 0; i < 26; ++i) {
            if (hashTable[i] != 0) {
                return false;
            }
        }
        return true;
    }
};
