class Solution {
public:
    bool validUtf8(vector<int>& data) {
        for (int i = 0; i < data.size(); ++i) {
            int count = 0;
            for (int j = 7; j >= 0 && (data[i] >> j & 1) == 1; --j) {
                ++count;
            }
            if (count <= 4 && count >= 2) {
                for (int k = 0; k < count - 1; ++k) {
                    if ((data[++i] >> 6 & 0b11) != 0b10) return false;
                }
            } else if (count != 0) {
                return false;
            }
        }
        return true;
    }
};