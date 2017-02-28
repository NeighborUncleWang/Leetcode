class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        unordered_set<int> prefix;
        int mask = 0;
        int result = 0;
        //这里必须int i = 31; i >= 0; --i
        //不能int i = 0; i < 32; ++i
        for (int i = 31; i >= 0; --i) {
            mask |= (1 << i);
            prefix.clear();
            for (int num : nums) {
                prefix.insert(num & mask);
            }
            int temp = result | (1 << i);
            for (int pre : prefix) {
                //这里不用担心prefix.find(pre ^ temp)返回的结果是pre自己
                //因为pre ^ pre == 0，而这里temp != 0
                if (prefix.find(pre ^ temp) != prefix.end()) {
                    result = temp;
                    break;
                }
            }
        }
        return result;
    }
};