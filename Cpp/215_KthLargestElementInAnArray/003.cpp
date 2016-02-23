class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums);
        int n = nums.size();
        return select(nums, 0, n - 1, k);
    }
private:
    void shuffle(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int i = left - 1;
        int value = nums[right];
        //my partition puts elements larger or equal to val to the left
        //elements smaller than val to the right
        //this is different from normal partition
        for (int j = left; j < right; ++j) {
            if (nums[j] >= value) {
                ++i;
                swap(nums[j], nums[i]);
            }
        }
        swap(nums[i + 1], nums[right]);
        return i + 1;
    }
    int select(vector<int>& nums, int left, int right, int k) {
        if (left >= right) {
            return nums[left];
        }
        int q = partition(nums, left, right);
        int numSmaller = q - left + 1;
        if (numSmaller == k) {
            return nums[q];
        } else if (numSmaller < k) {
            return select(nums, q + 1, right, k - numSmaller);
        } else {
            return select(nums, left, q - 1, k);
        }
    }
};