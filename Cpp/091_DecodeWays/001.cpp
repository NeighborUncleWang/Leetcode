class Solution {
public:
    int numDecodings(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int fn_2 = checkOneChar(s[0]);
        if (s.size() == 1) {
            return fn_2;
        }
        int fn_1 = fn_2 * checkOneChar(s[1]) + checkTwoChars(s[0], s[1]); 
        int fn = 0;
        for (int i = 2; i < s.size(); ++i) {
            if (checkOneChar(s[i])) {
                fn += fn_1;
            }
            if (checkTwoChars(s[i - 1], s[i])) {
                fn += fn_2;
            }
            fn_2 = fn_1;
            fn_1 = fn;
            fn = 0;
        }
        return fn_1;
    }
private:
    int checkOneChar(char ch) {
        return ch == '0' ? 0 : 1; 
    }
    int checkTwoChars(char ch1, char ch2) {
        if (ch1 == '1' || ch1 == '2' && ch2 <= '6') {
            return 1;
        } else {
            return 0;
        }
    }
};
