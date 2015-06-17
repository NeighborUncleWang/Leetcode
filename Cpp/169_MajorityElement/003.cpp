class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0, mask = 1, count;
        for (int i = 0; i < 32; ++i) {
            count = 0;
            for (auto j : nums) {
                if (mask & j){
                    ++count;
                } else {
                    --count;
                }
            }
            result = count > 0 ? result | mask : result;
            mask = mask << 1;
        }
        return result;
    }
};
