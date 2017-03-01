class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int*>> mem(size, vector<int*>(size, nullptr));
        return helper(nums, 0, size - 1, mem) >= 0;
    }
private:
    int helper(vector<int>& nums, int start, int end, vector<vector<int*>>& mem) {
        //这里不能通过初始化mem[start][end]为负的方式来判断
        //因为有可能通过计算之后mem[start][end]最终为负值
        if (mem[start][end] == nullptr) {
            mem[start][end] = new int(start == end ? nums[start] : max(nums[start] - helper(nums, start + 1, end, mem),
            nums[end] - helper(nums, start, end - 1, mem)));
        }
        return *mem[start][end];
    }
};