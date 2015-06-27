class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        int temp;
        for (auto i : tokens) {
            if (stack.size() == 0) {
                stack.push_back(stoi(i));
            } else {
                temp = stack.back();
                //The expression used in a switch statement must have an integral or enumerated type, so here we can't use switch
                if (i == "+") {
                    stack.pop_back();
                    //assert(stack.size() > 0)
                    stack.back() += temp;
                } else if (i == "-") {
                    stack.pop_back();
                    //assert(stack.size() > 0)
                    stack.back() -= temp;
                } else if (i == "*") {
                    stack.pop_back();
                    //assert(stack.size() > 0)
                    stack.back() *= temp;
                } else if (i == "/") {
                    stack.pop_back();
                    //assert(stack.size() > 0)
                    stack.back() /= temp;
                } else {
                    stack.push_back(stoi(i));
                }
            }
        }
        //assert(stack.size() == 1)
        return stack.back();
    }
};

