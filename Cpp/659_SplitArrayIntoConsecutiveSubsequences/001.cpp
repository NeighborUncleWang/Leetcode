class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> tails;
        for (int num : nums) {
            ++freq[num];
        }
        for (int num : nums) {
            if (freq[num] == 0) {
                continue;
            } else if (tails[num] > 0) {
                --tails[num];
                ++tails[num + 1];
            } else if (freq[num + 1] && freq[num + 2]) {
                --freq[num + 1];
                --freq[num + 2];
                ++tails[num + 3];
            } else {
                return false;
            }
            --freq[num];
        }
        return true;
    }
};
