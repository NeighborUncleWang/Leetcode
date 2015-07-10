class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        unordered_map<string, string::size_type> hashMap;
        for (string::size_type i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            auto substring = haystack.substr(i, needle.size());
            hashMap[substring] = i;
            if (hashMap.find(needle) != hashMap.end()) {
                return hashMap[substring];
            }
        }
        return -1;
    }
};
