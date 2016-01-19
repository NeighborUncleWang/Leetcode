class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string solution;
        dfs(result, solution, 0, 0, n);
        return result;
    }
private:
    void dfs(vector<string>& result, string& solution, int left, int right, int n) {
        if (left == right && left == n) {
            result.push_back(solution);
            return;
        } else if (right > left) {
            return;
        }
        solution.push_back('(');
        dfs(result, solution, left + 1, right, n);
        solution.pop_back();
        solution.push_back(')');
        dfs(result, solution, left, right + 1, n);
        solution.pop_back();
    }
};