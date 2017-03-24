class Solution {
public:
    int calculate(string s) {
        int res = 0, sign = 1;
        stack<int> st;
        for (int i = 0 ; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + s[i++] - '0';
                }
                res += sign * num;
                --i;
            } else if (s[i] == '+') {
                sign = 1;
            } else if (s[i] == '-') {
                sign = -1;
            } else if (s[i] == '(') {
                st.push(res);
                st.push(sign);
                res = 0;
                sign = 1;//记得不要漏了这条
            } else if (s[i] == ')') {
                int temp = st.top();
                st.pop();
                res = st.top() + temp * res;
                st.pop();
            }
        }
        return res;
    }
};