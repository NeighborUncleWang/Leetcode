class Solution {
public:
    string decodeString(string s) {
        int index = 0;
        return helper(s, index);
    }
private:
    string helper(string& s, int& index) {
        string result;
        while (index < s.size() && s[index] != ']') {
            if (!isdigit(s[index])) {
                result += s[index++];
            } else {
                int repeat = 0;
                while (index < s.size() && isdigit(s[index])) {
                    repeat = repeat * 10 + s[index++] - '0';
                }
                ++index;//'['
                string temp = helper(s, index);
                ++index;//']'
                for (int i = 0; i < repeat; ++i) {
                    result += temp;
                }
            }
        }
        return result;
    }
};