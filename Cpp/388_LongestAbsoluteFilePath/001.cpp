class Solution {
public:
    int lengthLongestPath(string input) {
        stack<int> st;
        st.push(0);
        int max_length = 0;
        for (int i = 0; i < input.size(); ++i) {
            int level = 0;
            while (i < input.size() && input[i] == '\t') {
                ++i;
                ++level;
            }
            //find the parent indent level
            while (level + 1 < st.size()) {
                st.pop();
            }
            int count = 0;
            bool is_file = false;
            while (i < input.size() && input[i] != '\n') {
                if (input[i] == '.') {
                    is_file = true;
                }
                ++i;
                ++count;
            }
            if (is_file) {
                max_length = max(max_length, st.top() + count);
            } else {
                st.push(st.top() + count + 1);
            }
        }
        return max_length;
    }
};