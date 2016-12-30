class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        for (int i = 0; i < words.size(); ++i) {
            //这里必须是j < words[i].size()而不是j < i
            for (int j = 0; j < words[i].size(); ++j) {
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};