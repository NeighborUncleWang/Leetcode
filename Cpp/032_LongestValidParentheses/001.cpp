class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int n = s.size();
        int longest = 0;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                if (st.empty()) {
                    st.push(i);
                } else {
                    s[st.top()] == '(' ? st.pop() : st.push(i);
                }
            }
        }
        if (st.empty()) return n;
        int a = n;
        while (!st.empty()) {
            int b = st.top();
            cout << b << endl;
            st.pop();
            longest = max(longest, a - b - 1);
            a = b;
        }
        longest = max(longest, a);
        return longest;
    }
};