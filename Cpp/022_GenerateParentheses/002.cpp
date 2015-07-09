class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) {
            return result;
        }
        string sequence;
        helper(sequence, result, 0, 0, 0, n);
        return result;
    }
private:
    void helper(string sequence, vector<string>& result, int leftNumber, int rightNumber, int deep, int n) {
        if (deep == 2 * n) {//actually we can test(rightNum == n && leftNum == n) here
            result.push_back(sequence);
            return;
        }
        if (leftNumber < n) {//actually the if (leftNumber < n) and if (rightNumber < leftNumber) can swap their order(first test rightNumber < leftNumber)
            helper(sequence + '(', result, leftNumber + 1, rightNumber, deep + 1, n);
        }
        if (rightNumber < leftNumber) {
            helper(sequence + ')', result, leftNumber, rightNumber + 1, deep + 1, n);
        }
    }
};
