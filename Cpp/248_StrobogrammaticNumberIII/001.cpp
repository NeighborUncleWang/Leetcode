class Solution {
private:
    void dfs(string strobo, string& low, string& high, 
    int left, int right, vector<string>& bases, int& count) {
        if (left > right) {
            //这里必须加strobo.size() == low.size()和 strobo.size() == high.size()
            //否则会出现"69"比"100"大而不被记录的情况
            //也不要用stoi,有可能会数值太大溢出
            if (strobo.size() == low.size() && strobo < low
            || strobo.size() == high.size() && strobo > high) {
                return;
            } else {
                ++count;
                return;
            }
        }
        for (string& base : bases) {
            strobo[left] = base[0];
            strobo[right] = base[1];
            if (strobo.size() > 1 && strobo[0] == '0' || left == right && base[0] != base[1]) {
                continue;
            }
            dfs(strobo, low, high, left + 1, right - 1, bases, count);
        }
    }
public:
    int strobogrammaticInRange(string low, string high) {
        vector<string> bases{"00", "11", "69", "88", "96"};
        int count = 0;
        for (int i = low.size(); i <= high.size(); ++i) {
            dfs(string(i, '0'), low, high, 0, i - 1, bases, count);
        }
        return count;
    }
};