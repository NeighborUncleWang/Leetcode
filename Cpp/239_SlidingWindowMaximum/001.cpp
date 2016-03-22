class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            if (!dq.empty() && dq.front() < i + 1 - k) {
                dq.pop_front();
            }
            //here we should use while instead of if, otherwise can't pass [4, 3, 11], 3 case
            //这里也可以用nums[dq.back()] <= nums[i]
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            //整个过程deque中的元素对应的值是单调递减的(monotonic decreasing)
            //所以nums[dq.front()]对应的是最大值
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
