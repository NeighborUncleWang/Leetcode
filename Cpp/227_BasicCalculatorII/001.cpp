class Solution {
public:
    int calculate(string s) {
        stack<int> valStack;
        stack<char> opStack;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] >= '0' && s[i] <= '9') {
                int number = 0;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    number *= 10;
                    number += s[i] - '0';
                    ++i;
                }
                --i;
                valStack.push(number);
            } else if (s[i] != ' ') {
                while (!opStack.empty() && notLowerThan(opStack.top(), s[i])) {
                    applyOperator(valStack, opStack);
                }
                opStack.push(s[i]);
            }
        }
        while (!opStack.empty()) {
            applyOperator(valStack, opStack);
        }
        return valStack.top();
    }
private:
    void applyOperator(stack<int>& valStack, stack<char>& opStack) {
        int number1 = valStack.top();
        valStack.pop();
        switch (opStack.top()) {
            case '+':
                valStack.top() = valStack.top() + number1;
                break;
            case '-':
                valStack.top() = valStack.top() - number1;
                break;
            case '*':
                valStack.top() = valStack.top() * number1;
                break;
            case '/':
                valStack.top() = valStack.top() / number1;
                break;
        }
        opStack.pop();
    }
    bool notLowerThan(char top, char current) {
        if (current == '*' || current == '/') {
            return top == '*' || top == '/';
        } else {
            return true;
        }
    }
};
