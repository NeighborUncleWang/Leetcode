class Solution {
public:
    bool isNumber(string s) {
        auto first = s.find_first_not_of(' ');
        auto last = s.find_last_not_of(' ');
        //or I can use first == -1 here
        if (first == string::npos) {
            return false;
        }
        s = s.substr(first, last - first + 1);//trim the string
        bool hasDot = false;
        bool hasE = false;
        bool hasNumber = false;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '.') {
                if (hasDot || hasE || (i == 0 || s[i - 1] > '9' || s[i - 1] < '0') 
                && (i == s.size() - 1 || s[i + 1] > '9' || s[i + 1] < '0')) {
                    return false;
                }
                hasDot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                //不用判断!(s[i - 1] >= '0' && s[i - 1] <= '9' || s[i - 1] == '.')，因为e前面不可能是+-,因为+-要求后面跟数字或者'.'
                if (hasE || i == 0 || i == s.size() - 1) {//e前面可以是'.'，46.e3
                    return false;
                }
                hasE = true;
            } else if (s[i] == '+' || s[i] == '-') {
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E' || i == s.size() - 1
                || !(s[i + 1] >= '0' && s[i + 1] <= '9' || s[i + 1] == '.')) {
                    return false;
                }
            } else if (s[i] >= '0' && s[i] <= '9') {
            } else {
                return false;
            }
        }
        return true;
    }
};
