class Solution {
public:
    int longestValidParentheses(string s) {
        stack<string::size_type> indexStack;
        string::size_type maxLength = 0;
        for (string::size_type i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                indexStack.push(i);
            } else {
                if (indexStack.empty() == false && s[indexStack.top()] == '(') {
                    indexStack.pop();
                    /*如果pop了之后stack不为空，那么最长的有效括号是当前
					 * 右括号的index和栈里面括号index + 1这段序列所构成的括号，
					 * 因为中间括号有可能被pop掉，所以无法通过pop之前的栈顶index来
					 * 得到最长括号序列长度，有点类似Largest Rectangle in Histogram这题
					 * 的处理方法
					 */
                    maxLength = max(maxLength, i - (indexStack.empty() ? 0 : indexStack.top() + 1) + 1);
                } else {
                    indexStack.push(i);
                }
            }
        }
        return maxLength;
    }
};
