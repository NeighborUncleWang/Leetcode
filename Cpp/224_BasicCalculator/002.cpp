class Solution {
public:
    int calculate(string s) {
        stack<int> valueStack;
        stack<char> operatorStack;
        for (int i = 0; i < s.size(); ++i) {
            if (isdigit(s[i])) {
                int number = 0;
                while (i < s.size() && isdigit(s[i])) {
                    number = number * 10 + s[i] - '0';
                    ++i;
                }
                --i;
                valueStack.push(number);
            } else if (s[i] == '(') {
                operatorStack.push(s[i]);
            } else if (s[i] == ')' || s[i] == '+' || s[i] == '-') {
                while (!operatorStack.empty() && operatorStack.top() != '(') {
                    applyOperator(valueStack, operatorStack);
                }
                if (s[i] == ')') {
                    operatorStack.pop();
                } else {
                    operatorStack.push(s[i]);
                }
            }
        }
        while (!operatorStack.empty()) {
            applyOperator(valueStack, operatorStack);
        }
        return valueStack.top();
    }
private:
    function<int(int, int)> chooseOperator(char c) {
        switch (c) {
            case '+':
                return plus<int>();
            case '-':
                return minus<int>();
            default:
                return plus<int>();
        }
    }
    void applyOperator(stack<int>& valueStack, stack<char>& operatorStack) {
            int number1 = valueStack.top();
            valueStack.pop();
            valueStack.top() = chooseOperator(operatorStack.top())(valueStack.top(), number1);
            operatorStack.pop();
    }
};