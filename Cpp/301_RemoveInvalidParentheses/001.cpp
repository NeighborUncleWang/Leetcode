class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int removeLeft = 0;
        int removeRight = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++removeLeft;
            } else if (ch == ')') {
                removeLeft == 0 ? ++removeRight : --removeLeft;
            }
        }
        unordered_set<string> result;
        string sequence;
        dfs(result, 0, s.size(), removeLeft, removeRight, 0, s, sequence);
        return vector<string>(result.begin(), result.end());
    }
private:
    void dfs(unordered_set<string>& result, int index, int n, int removeLeft, int removeRight,
             int open, string& s, string& sequence) {
        if (index == n && removeLeft == 0 && removeRight == 0 && open == 0) {
            result.insert(sequence);
            return;
        } else if (index == n || removeLeft < 0 || removeRight < 0 || open < 0) {
            return;
        }
        char ch = s[index];
        if (ch == '(') {
            dfs(result, index + 1, n, removeLeft - 1, removeRight, open, s, sequence);
            sequence.push_back(ch);
            dfs(result, index + 1, n, removeLeft, removeRight, open + 1, s, sequence);
        } else if (ch == ')') {
            dfs(result, index + 1, n, removeLeft, removeRight - 1, open, s, sequence);
            sequence.push_back(ch);
            dfs(result, index + 1, n, removeLeft, removeRight, open - 1, s, sequence);
        } else {
            sequence.push_back(ch);
            dfs(result, index + 1, n, removeLeft, removeRight, open, s, sequence);
        }
        sequence.pop_back();
    }
};