class Solution {
public:
    string parseTernary(string expression) {
        stack<char> st;
        for (int i = (int)expression.size() - 1; i >= 0; --i) {
            char ch = expression[i];
            if (!st.empty() && st.top() == '?') {
                st.pop();//'?'
                char first = st.top();
                st.pop();
                st.pop();//':'
                char second = st.top();
                st.pop();
                ch == 'T' ? st.push(first) : st.push(second);
            } else {
                st.push(ch);
            }
        }
        return string(1, st.top());
    }
};