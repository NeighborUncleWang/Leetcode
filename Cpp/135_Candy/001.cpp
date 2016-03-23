class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        vector<int> nums(size, 1);
        for (int i = 1; i < size; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                nums[i] = nums[i - 1] + 1;
            }
        }
        int total = nums.back();
        for (int i = size - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                nums[i] = max(nums[i], nums[i + 1] + 1);
            }
            total += nums[i];
        }
        //也可以直接return accumulate(nums.begin(), nums.end(), 0);
        return total;
    }
};