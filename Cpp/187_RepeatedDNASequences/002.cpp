class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> encoder{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        int i = 0;
        unordered_map<int, int> hashMap;
        int code = 0;
        for ( ; i < 9; ++i) {
            code = code << 2 | encoder[s[i]];
        }
        vector<string> result;
        for ( ; i < s.size(); ++i) {
            code = (code << 2 | encoder[s[i]]) & 0x000fffff;
            if (hashMap[code]++ == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};
