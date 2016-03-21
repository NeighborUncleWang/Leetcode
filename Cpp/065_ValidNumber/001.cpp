class Solution {
public:
    bool isNumber(string s) {
        int begin = s.find_first_not_of(' ');
        if (begin == string::npos) {
            return false;
        }
        int end = s.find_last_not_of(' ');
        bool hasSign = false;
        bool hasDigit = false;
        bool hasDot = false;
        bool hasE = false;
        for (int i = begin; i <= end; ++i) {
            if (s[i] == '+' || s[i] == '-') {
                if (hasSign || hasDigit || hasDot) {
                    return false;
                } else {
                    hasSign = true;
                }
            } else if (s[i] == '.') {
                if (hasDot || hasE) {
                    return false;
                } else {
                    hasDot = true;
                }
            } else if (s[i] == 'e') {
                //如果看到e,把所有变量都设成false
                if (!hasDigit || hasE) {
                    return false;
                } else {
                    hasE = true;
                    hasSign = false;
                    hasDigit = false;
                    hasDot = false;
                }
            } else if (isdigit(s[i])) {
                hasDigit = true;
            } else {
                return false;
            }
        }
        return hasDigit;
    }
};