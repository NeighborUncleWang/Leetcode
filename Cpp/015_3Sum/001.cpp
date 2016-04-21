class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> result;
        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            for (int left = i + 1, right = n - 1; left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left;
                    --right;
                    //这里必须先++left, --right
                    //因为如果nums里面的值都是distinct的话，后面两个while loop不会修改left和right
                    //那样导致死循环
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                } else if (sum < 0) {
                    ++left;
                } else if (sum > 0) {
                    --right;
                }
            }
        }
        return result;
    }
};