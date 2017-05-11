class Solution {
public:
    bool checkRecord(string s) {
        bool absent = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                if (absent) {
                    return false;
                } else {
                    absent = true;
                }
            } else if (s[i] == 'L') {
                if (i > 1 && s[i - 1] == 'L' && s[i - 2] == 'L') {
                    return false;
                }
            }
        }
        return true;
    }
};