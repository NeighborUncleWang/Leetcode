class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        for (int i = 0; i < num.size(); ++i) {
            string currentNumStr = num.substr(0, i + 1);
            long long currentNum = stol(currentNumStr);
            if (to_string(currentNum).size() != currentNumStr.size()) continue;
            dfs(currentNumStr, num, result, i + 1, currentNum, currentNum, target, '#');
        }
        return result;
    }
private:
    void dfs(string currentExpression, const string& num, vector<string>& result, 
    int index, long long previousNum, long long previousValue, int target, char op) {
        if (index == num.size() && previousValue == target) {
            result.push_back(currentExpression);
            return;
        }
        for (int i = index; i < num.size(); ++i) {
            string currentNumStr = num.substr(index, i - index + 1);
            long long currentNum = stol(currentNumStr);
            if (to_string(currentNum).size() != currentNumStr.size()) continue;
            dfs(currentExpression + '+' + currentNumStr, num, result, i + 1,
            currentNum, previousValue + currentNum, target, '+');
            dfs(currentExpression + '-' + currentNumStr, num, result, i + 1,
            currentNum, previousValue - currentNum, target, '-');
            long long newPreviousValue = 0;
            if (op == '+') {
                newPreviousValue = previousValue - previousNum + previousNum * currentNum;
            } else if (op == '-') {
                newPreviousValue = previousValue + previousNum - previousNum * currentNum;
            } else {
                newPreviousValue = previousValue * currentNum;
            }
            dfs(currentExpression + '*' + currentNumStr, num, result, i + 1,
            previousNum * currentNum, newPreviousValue, target, op);
        }
    }
};