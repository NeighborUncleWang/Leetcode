class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, string::size_type> expectCount;
        for (string::size_type i = 0; i < t.size(); ++i) {
            ++expectCount[t[i]];
        }
        unordered_map<char, string::size_type> realCount;
        string::size_type left = 0;
        string::size_type count = 0;
        string::size_type minLength = numeric_limits<string::size_type>::max();
        string::size_type minLeft = 0;
        for (string::size_type right = 0; right < s.size(); ++right) {
            if (expectCount.find(s[right]) != expectCount.end()) {
                if (realCount[s[right]] < expectCount[s[right]]) {
                    ++count;
                }
                ++realCount[s[right]];
            }
            while (count == t.size()) {
                if (right - left + 1 < minLength) {
                    minLeft = left;
                    minLength = right - left + 1;
                }
                if (expectCount.find(s[left]) != expectCount.end()) {//it means s[left] is in the expectCount, in the string t
                    if (realCount[s[left]] <= expectCount[s[left]]) {
                        --count;
                    }
                    --realCount[s[left]];
                }
                ++left;
            }
        }
        if (minLength > s.size()) {
            return "";
        } else {
            return s.substr(minLeft, minLength);
        }
    }
};
