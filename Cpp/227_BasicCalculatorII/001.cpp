class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int num = 0;
        char sign = '+';
        int size = s.size();
        for (int i = 0; i <= size; ++i) {
            if (i < size && isdigit(s[i])) {
                num = num * 10 + s[i] - '0';
            } else if (i == size || s[i] != ' ') {
                if (sign == '+') {
                    st.push(num);
                } else if (sign == '-') {
                    st.push(-num);
                } else if (sign == '*') {
                    st.top() = st.top() * num;
                } else if (sign == '/') {
                    st.top() = st.top() / num;
                }
                num = 0;
                if (i < size) {
                    sign = s[i];
                }
            }
        }
        int result = 0;
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        return result;
    }
};