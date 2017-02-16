class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        if (words.empty()) return true;
        for (int i = 0; i < words.size(); ++i) {
            //这里必须是j < words[i].size()而不是j < i
            for (int j = 0; j < words[i].size(); ++j) {
                //检查j >= words[i].size()是为了避免那行的word太长
                //检查i >= words[j].size()是为了避免那行的word太短
                //for loop必须从j = 0开始因为从j = i + 1开始的话当i >= words[j].size()的时候，
                //就不会进入这个第二个for loop来检查，导致漏过了invalid的情况
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) {
                    return false;
                }
            }
        }
        return true;
    }
};