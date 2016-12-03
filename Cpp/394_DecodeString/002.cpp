class Solution {
public:
    string decodeString(string s) {
        stack<int> count_st;
        stack<string> res_st;
        string result;
        for (int i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                int repeat = 0;
                while (i < s.size() && isdigit(s[i])) {
                    repeat = repeat * 10 + s[i] - '0';
                    ++i;
                }
                count_st.push(repeat);
            } else if (s[i] == '[') {
                res_st.push(result);
                result = "";
                ++i;
            } else if (s[i] == ']') {
                int repeat = count_st.top();
                count_st.pop();
                string temp = res_st.top();
                res_st.pop();
                for (int j = 0; j < repeat; ++j) {
                    temp += result;
                }
                result = temp;
                ++i;
            } else {
                result += s[i++];
            }
        }
        return result;
    }
};