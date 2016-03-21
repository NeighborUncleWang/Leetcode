class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.find_last_not_of(' ');
        if (end == string::npos) return 0;
        int start = s.rfind(' ', end);
        return end - start;
    }
};