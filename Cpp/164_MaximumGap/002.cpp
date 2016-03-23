class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        for (int base = 1; maxNum / base; base *= 10) {
            countingSort(nums, base);
        }
        int maxGap = 0;
        for (int i = 1; i < nums.size(); ++i) {
            maxGap = max(maxGap, nums[i] - nums[i - 1]);
        }
        return maxGap;
    }
private:
    void countingSort(vector<int>& nums, int base) {
        int size = nums.size();
        vector<int> count(10, 0);
        for (int num : nums) {
            ++count[num / base % 10];
        }
        for (int i = 1; i < count.size(); ++i) {
            count[i] += count[i - 1];
        }
        vector<int> output(size, 0);
        for (int i = size - 1; i >= 0; --i) {
            output[count[nums[i] / base % 10] - 1] = nums[i];
            --count[nums[i] / base % 10];
        }
        nums = move(output);
    }
};