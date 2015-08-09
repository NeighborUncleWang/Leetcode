class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMap;
        for (int i = 0; i < s.size(); ++i) {
            if (hashMap.find(s[i]) == hashMap.end()) {
                hashMap[s[i]] = t[i];
            } else {
                if (hashMap[s[i]] != t[i]) {
                    return false;
                }
            }
        }
        hashMap.clear();
        for (int i = 0; i < t.size(); ++i) {
            if (hashMap.find(t[i]) == hashMap.end()) {
                hashMap[t[i]] = s[i];
            } else {
                if (hashMap[t[i]] != s[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};
