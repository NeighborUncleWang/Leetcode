class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int temp = nums.top();
                nums.pop();
                if (token == "+") {
                    nums.top() += temp;
                } else if (token == "-") {
                    nums.top() -= temp;
                } else if (token == "*") {
                    nums.top() *= temp;
                } else {
                    nums.top() /= temp;
                }
            //不要直接判断isdigit(token[0])
            //因为token = "-4"这种情况会导致出错
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};