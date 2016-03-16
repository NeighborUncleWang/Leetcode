class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start = 0;
        int size = nums.size();
        for (; k %= size; start += k, size -= k) {
            for (int i = 0; i < k; ++i) {
            	//将当前nums最前面k个和最后面k个swap
                swap(nums[start + i], nums[start + size - k + i]);
            }
        }
    }
};