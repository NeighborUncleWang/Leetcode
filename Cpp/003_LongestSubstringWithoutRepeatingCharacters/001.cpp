class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int maxLength = 1;
        unordered_set<char> hashSet;
        int walker = 0, runner = 0;
        while (runner < s.size()) {
            auto position = hashSet.find(s[runner]);
            if (position == hashSet.end()) {
                hashSet.insert(s[runner]);
            } else {
                maxLength = max(maxLength, runner - walker);
                while (s[walker] != s[runner]) {
                    hashSet.erase(s[walker]);
                    ++walker;
                }
                //don't add hashSet.erase(s[walker]) here, since you didn't add current s[runner] into the hashSet
                ++walker;
            }
            ++runner;
        }
        maxLength = max(maxLength, runner - walker);
        return maxLength;
    }
};
