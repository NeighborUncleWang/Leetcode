class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> vec(3);
        vector<vector<int>> result;
        for (int i = 0; i < nums.size(); ++i) {
            int head = i + 1, tail = nums.size() - 1;
            while (head < tail) {
                int sum = nums[i] + nums[head] + nums[tail];
                if (sum == 0) {
                    vec[0] = nums[i];
                    vec[1] = nums[head];
                    vec[2] = nums[tail];
                    result.push_back(vec);
                    ++head;
                    --tail;
                    while (head < tail && nums[head] == nums[head - 1]) { ++head; }
                    while (head < tail && nums[tail] == nums[tail + 1]) { --tail; }
                } else if (sum > 0) {
                    --tail;
                    while (head < tail && nums[tail] == nums[tail + 1]) { --tail; }
                } else {
                    ++head;
                    while (head < tail && nums[head] == nums[head - 1]) { ++head; }
                }
            }
            while (i < nums.size() && nums[i] == nums[i + 1]) {
                ++i;
            }
        }
        return result;
    }
};
