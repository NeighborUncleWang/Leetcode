class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count = 0, res = 0;
        unordered_map<int, int> map{{0, -1}};
        for (int i = 0; i < nums.size(); ++i) {
            count += nums[i] == 0 ? -1 : 1;
            if (map.find(count) != map.end()) {
                res = max(res, i - map[count]);
            } else {
                map[count] = i;
            }
        }
        return res;
    }
};