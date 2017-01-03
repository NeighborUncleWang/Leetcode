class Solution {
public:
   bool makesquare(vector<int>& nums) {
        int n = nums.size();
        int all = 1 << n;
        int sums = accumulate(nums.begin(), nums.end(), 0);
        if (sums % 4) return false;
        //sort is not necessary, but can improve the speed
        sort(nums.begin(), nums.end(), greater<int>());
        int target = sums / 4;
        vector<int> quarter_mask;
        vector<bool> half_mask(all, false);
        for (int mask = 0; mask < all; ++mask) {
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if ((mask >> i) & 1) {
                    sum += nums[i];
                    if (sum > target) break;
                }
            }
            if (sum == target) {
                for (int quarter : quarter_mask) {
                    if ((quarter & mask) == 0) {
                        int valid_half = quarter | mask;
                        half_mask[valid_half] = true;
                        if (half_mask[~(valid_half) & (all - 1)]) return true;
                    }
                }
                quarter_mask.push_back(mask);
            }
        }
        return false;
    }
};