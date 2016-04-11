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
        dfs(s, 0, result, sequence, 0, removeLeft, removeRight);
        return vector<string>(result.begin(), result.end());
    }
private:
    void dfs(string& s, int index, unordered_set<string>& result, string& sequence, 
        int open, int removeLeft, int removeRight) {
        if (index == s.size() && open == 0 && removeLeft == 0 && removeRight == 0) {
            result.insert(sequence);
            return;
        } else if (index == s.size() || open < 0 || removeLeft < 0 || removeRight < 0) {
            return;
        }
        char ch = s[index];
        if (ch == '(') {
            dfs(s, index + 1, result, sequence, open, removeLeft - 1, removeRight);
            sequence.push_back(ch);
            dfs(s, index + 1, result, sequence, open + 1, removeLeft, removeRight);
        } else if (ch == ')') {
            dfs(s, index + 1, result, sequence, open, removeLeft, removeRight - 1);
            sequence.push_back(ch);
            dfs(s, index + 1, result, sequence, open - 1, removeLeft, removeRight);
        } else {
            sequence.push_back(ch);
            dfs(s, index + 1, result, sequence, open, removeLeft, removeRight);
        }
        sequence.pop_back();
    }
};