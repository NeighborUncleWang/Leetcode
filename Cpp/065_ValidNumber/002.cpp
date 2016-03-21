class Solution {
public:
    bool isNumber(string s) {
        int iter = s.find_first_not_of(' ');
        if (iter == string::npos) return false;
        int end = s.find_last_not_of(' ');
        if (s[iter] == '+' || s[iter] == '-') {
            ++iter;
        }
        int numDigit = 0;
        int numPoint = 0;
        //如果不依赖于string 以'\0'结尾的话，每次都得check iter<=end
        //但是如果事先知道string 以'\0'结尾，就不用check了
        for (; iter <= end && (isdigit(s[iter]) || s[iter] == '.'); ++iter) {
            s[iter] == '.' ? ++numPoint : ++numDigit;
        }
        if (numPoint > 1 || numDigit < 1) {
            return false;
        }
        if (iter <= end && s[iter] == 'e') {
            ++iter;
            if (s[iter] == '+' || s[iter] == '-') {
                ++iter;
            }
            numDigit = 0;
            for (; iter <= end && isdigit(s[iter]); ++iter) {
                ++numDigit;
            }
            if (numDigit < 1) {
                return false;
            }
        }
        return iter == end + 1;
    }
};