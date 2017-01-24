class Solution {
private:
    string collapse(vector<vector<string>>& dp, string& s, int i, int j) {
        string temp = s.substr(i, j - i + 1);
        auto pos = (temp + temp).find(temp, 1);
        if (pos == temp.size()) {
            return temp;
        } else {
            //不要写成return to_string(temp.size() / pos) + "[" + temp.substr(0, pos) + "]";
            /*Input:"abbbabbbcabbbabbbc"
             *Output:"2[abbbabbbc]"
             *Expected:"2[2[abbb]c]"
            */
            //这个case过不去
            return to_string(temp.size() / pos) + "[" + dp[i][i + pos - 1] + "]";
        }
    }
public:
    string encode(string s) {
        int size = s.size();
        vector<vector<string>> dp(size, vector<string>(size));
        for (int l = 1; l <= size; ++l) {
            for (int i = 0; i < size - l + 1; ++i) {
                int j = i + l - 1;
                dp[i][j] = s.substr(i, l);
                if (l > 4) {
                    for (int k = i; k < j; ++k) {
                        if (dp[i][k].size() + dp[k + 1][j].size() < dp[i][j].size()) {
                            dp[i][j] = dp[i][k] + dp[k + 1][j];
                        }
                    }
                    string temp = collapse(dp, s, i, j);
                    if (temp.size() < dp[i][j].size()) {
                        dp[i][j] = temp;
                    }
                }
            }
        }
        return dp[0][size - 1];
    }
};