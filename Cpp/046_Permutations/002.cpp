class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> solution;
        vector<int>::size_type n = nums.size();
        if (n == 0) {
            return result;
        }
        helper(nums, n, solution, result);
        return result;
    }
private:
	//we can also use pass by value to pass the vector nums, that will be less efficient
    void helper(vector<int>& nums, size_t n, vector<int>& solution, vector<vector<int>>& result) {
        if (n == 0) {
            result.push_back(solution);
            return;
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            solution.push_back(nums[i]);
            auto temp = nums;
            temp.erase(temp.begin() + i);
            helper(temp, n - 1, solution, result);
            solution.pop_back();
        }
    }
};
