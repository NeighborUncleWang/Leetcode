class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
private:
    int helper(vector<int>& nums, int start, int end) {
        if (end - start < 2) {
            return 0;
        }
        int mid = start + (end - start) / 2;
        int count = helper(nums, start, mid) + helper(nums, mid, end);
        for (int i = start, j = mid; j < end; ++j) {
            while (i < mid && nums[i] <= 2ll * nums[j]) ++i;
            if (i == mid) break;
            count += mid - i;
        }
        // vector<int> temp(end - start);
        // for (int i = 0, i1 = start, i2 = mid; i < end - start; ++i) {
        //     if (i1 < mid && (i2 == end || nums[i1] < nums[i2])) {
        //         temp[i] = nums[i1++];
        //     } else {
        //         temp[i] = nums[i2++];
        //     }
        // }
        // move(temp.begin(), temp.end(), nums.begin() + start);
        //c++有一个inplace_merge函数可以完成上面所有命令ORZ
        inplace_merge(nums.begin() + start, nums.begin() + mid, nums.begin() + end);
        return count;
    }
};