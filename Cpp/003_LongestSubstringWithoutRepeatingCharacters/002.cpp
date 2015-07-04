class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> charArray(256, -1);
        int walker = 0, runner = 0;
        int maxLength = 0;
        while (runner < s.size()) {
            if (charArray[s[runner]] >= walker) {//s[runner] is a duplicate char
                maxLength = max(maxLength, runner - walker);
                walker = charArray[s[runner]] + 1;//move walker to the next position of the first appearance of the duplicate char
            }
            charArray[s[runner]] = runner;
            ++runner;
        }
        maxLength = max(maxLength, runner - walker);
        return maxLength;
    }
};
