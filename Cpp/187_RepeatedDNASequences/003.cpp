class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> encode{{'A', 1}, {'C', 2}, {'G', 3}, {'T', 4}};
        unordered_map<int, int> substrMap;
        int base = encode.size();
        int maxBase = pow(base, 9);
        vector<string> result;
        for (int i = 0, hashCode = 0; i < s.size(); ++i) {
            if (i > 9) {
                hashCode -= encode[s[i - 10]] * maxBase;
            }
            hashCode = hashCode * base + encode[s[i]];
            if (substrMap[hashCode]++ == 1) {
                result.push_back(s.substr(i - 9, 10));
            }
        }
        return result;
    }
};