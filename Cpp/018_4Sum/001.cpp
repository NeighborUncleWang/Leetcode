class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> vec(4);
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i <= n - 4; ++i) {
            for (int j = i + 1; j <= n - 3; ++j) {
                int head = j + 1, tail = nums.size() - 1;
                while (head < tail) {
                    int sum = nums[i] + nums[j] + nums[head] + nums[tail];
                    if (target == sum) {
                        vec[0] = nums[i];
                        vec[1] = nums[j];
                        vec[2] = nums[head];
                        vec[3] = nums[tail];
                        result.push_back(vec);
                        ++head;
                        --tail;
                        while (head < tail && nums[head] == nums[head - 1]) { ++head; };
                        while (head < tail && nums[tail] == nums[tail + 1]) { --tail; }; 
                    } else if (sum > target) {
                        --tail;
                        while (head < tail && nums[tail] == nums[tail + 1]) { --tail; };
                    } else {
                        ++head;
                        while (head < tail && nums[head] == nums[head - 1]) { ++head; };
                    }
                }
                while (j <= n - 3 && nums[j] == nums[j + 1]) { ++j; };
            }
            while (i <= n - 4 && nums[i] == nums[i + 1]) { ++i; };
        }
        return result;
    }
};
