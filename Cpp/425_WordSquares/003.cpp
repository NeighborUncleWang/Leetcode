class Solution {
public:
    vector<vector<string>> wordSquares(vector<string>& words) {
        int n = words[0].size();
        if (n == 0) return vector<vector<string>>();
        vector<vector<string>> res;
        vector<string> square;
        dfs(words, res, square, 0, n);
        return res;
    }
private:
    void dfs(vector<string>& words, vector<vector<string>>& res, vector<string>& square, int index, int n) {
        if (index == n) {
            res.push_back(square);
            return;
        }
        for (string& word : words) {
            bool fit = true;
            //判断当前word是否fit的时候
            //因为有所有word长度一样的前提条件
            //所以才可以这么简单的判断
            //否则要像ValidWordSquare那样判断 i >= square.size() || index >= square[i].size() ||
            //word[i] != square[i][index]
            //这题每个word可以重用，否则要用visited[]来判断之前有没有用过这个word
            for (int i = 0; i < index; ++i) {
                if (word[i] != square[i][index]) {
                    fit = false;
                    break;
                }
            }
            if (fit) {
                square.push_back(word);
                dfs(words, res, square, index + 1, n);
                square.pop_back();
            }
        }
    }
};