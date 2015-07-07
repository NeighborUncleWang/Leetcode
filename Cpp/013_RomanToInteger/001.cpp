class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (i > 0 && romanCharTable(s[i]) > romanCharTable(s[i - 1])) {
                result = result - 2 * romanCharTable(s[i - 1]);
            }
            result += romanCharTable(s[i]);
        }
        return result;
    }
private:
    inline int romanCharTable(char s) {
        switch (s) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
        }
    }
};
