class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int*>> mem(size, vector<int*>(size, nullptr));
        return helper(nums, 0, size - 1, mem) >= 0;
    }
private:
    int helper(vector<int>& nums, int start, int end, vector<vector<int*>>& mem) {
        if (mem[start][end] == nullptr) {
            mem[start][end] = new int(start == end ? nums[start] : max(nums[start] - helper(nums, start + 1, end, mem),
            nums[end] - helper(nums, start, end - 1, mem)));
        }
        return *mem[start][end];
    }
};