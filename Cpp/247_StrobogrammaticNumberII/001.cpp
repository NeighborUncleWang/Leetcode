class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> strobos;
        if (n & 1) {
            strobos = {"0", "1", "8"};
        } else {
            strobos = {""};
        }
        vector<string> base{"00", "11", "69", "88", "96"};
        int baseSize = base.size();
        while (n > 1) {
            n -= 2;
            vector<string> temp;
            for (string strobo : strobos) {
                //n > 1说明这个不是最后一次while loop，还会有下一次
                for (int i = n > 1 ? 0 : 1; i < baseSize; ++i) {
                    temp.push_back(base[i][0] + strobo + base[i][1]);
                }
            }
            strobos = move(temp);
        }
        return strobos;
    }
};