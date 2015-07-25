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
        vector<vector<bool>> wordDict(s.size(), vector<bool>(s.size(), false));
        createDict(s, wordDict);
        helper(s, 0, solution, result, wordDict);
        return result;
    }
private:
    void helper(string& s, int startIndex, vector<string>& solution, vector<vector<string>>& result, 
    vector<vector<bool>>& wordDict) {
        if (startIndex == s.size()) {
            result.push_back(solution);
            return;
        }
        string sequence;
        for (int i = startIndex; i < s.size(); ++i) {
            sequence += s[i];
            if (wordDict[startIndex][i]) {
                solution.push_back(sequence);
                helper(s, i + 1, solution, result, wordDict);
                solution.pop_back();
            }
        }
    }
    void createDict(string& s, vector<vector<bool>>& wordDict) {
        for (int i = s.size() - 1; i >= 0; --i) {
            for (int j = i; j < s.size(); ++j) {
                if (s[i] == s[j] && (j - i <= 2 || wordDict[i + 1][j - 1])) {
                    wordDict[i][j] = true;
                }
            }
        }
    }
};
