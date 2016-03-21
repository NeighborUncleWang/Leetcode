class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int number = 0;
        int result = 0;
        int sign = 1;
        for (char ch : s) {
            if (isdigit(ch)) {
                number = number * 10 + ch - '0';
            } else if (ch == '+' || ch == '-') {
                result += sign * number;
                number = 0;
                sign = ch == '+' ? 1 : -1;
            } else if (ch == '(') {
                st.push(result);
                st.push(sign);
                sign = 1;
                result = 0;
            } else if (ch == ')') {
                result += sign * number;
                result *= st.top();
                st.pop();
                result += st.top();
                st.pop();
                number = 0;
            }
        }
        if (number) result += sign * number;
        return result;
    }
};