class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> solution;
        //it depends on when the s is empty, what shall we output
        //if we need to output[""], then we can delete the 
        //following code block and just call the helper function
        if (s.size() == 0) {
            return result;
        }
        helper(s, 0, solution, result);
        return result;
    }
private:
    void helper(string& s, int startIndex, vector<string>& solution, vector<vector<string>>& result) {
        if (startIndex == s.size()) {
            result.push_back(solution);
            return;
        }
        string sequence;
        for (int i = startIndex; i < s.size(); ++i) {
            sequence += s[i];
            if (isPalindrome(sequence)) {
                solution.push_back(sequence);
                helper(s, i + 1, solution, result);
                solution.pop_back();
            }
        }
    }
    bool isPalindrome(string& s) {
        int start = 0;
        int end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) {
                return false;
            }
            ++start;
            --end;
        }
        return true;
    }
};
