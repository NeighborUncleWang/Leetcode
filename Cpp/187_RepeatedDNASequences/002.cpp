class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int i = 0;
        int code = 0;
		//since the char 'A', 'C', 'G', 'T' is different for their lowest 3 bits, so we use these 3 bits to encode these chars
        for ( ; i < 9; ++i) {
            code = code << 3 | (s[i] & 0x00000007);
        }
        unordered_map<int, int> hashMap;
        vector<string> result;
        for ( ; i < s.size(); ++i) {
            code = (code << 3 | (s[i] & 0x00000007)) & 0x3FFFFFFF;
            if (hashMap[code]++ == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};
