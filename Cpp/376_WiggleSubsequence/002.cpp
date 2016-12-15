class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int size = nums.size();
        if (size == 0) return 0;
        //ends_large[i]表示到index i为止ends_large的subsequence长度
        //不一定最后一个元素是nums[i]
        //ends_small[i]同理
        //所以最后才能直接返回ends_large.back()
        //否则要记录两个vector里出现过的最大值然后返回
        vector<int> ends_large(size, 1);
        vector<int> ends_small(size, 1);
        for (int i = 1; i < size; ++i) {
            if (nums[i] > nums[i - 1]) {
                ends_large[i] = max(ends_large[i - 1], ends_small[i - 1] + 1);
                ends_small[i] = ends_small[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                ends_small[i] = max(ends_small[i - 1], ends_large[i - 1] + 1);
                ends_large[i] = ends_large[i - 1];
            } else {
                ends_small[i] = ends_small[i - 1];
                ends_large[i] = ends_large[i - 1];
            }
        }
        return max(ends_large.back(), ends_small.back());
    }
};