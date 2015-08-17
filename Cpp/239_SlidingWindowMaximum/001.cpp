class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            //here we can either use if or while, but the while loop will only be excuted once
            if (!dq.empty() && dq.front() < i + 1 - k) {
                dq.pop_front();
            }
            //here we should use while instead of if, otherwise can't pass [4, 3, 11], 3 case
            while (!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                result.push_back(nums[dq.front()]);
            }
        }
        return result;
    }
};
