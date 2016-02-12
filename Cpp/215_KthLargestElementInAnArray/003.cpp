class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        shuffle(nums);
        int n = nums.size();
        return select(nums, 0, n - 1, k);
    }
private:
    int select(vector<int>& nums, int left, int right, int k) {
        if (left >= right) {
            return nums[left];
        }
        int n = nums.size();
        int j = partition(nums, left, right);
        int order = j - left + 1;
        if (k == order) {
            return nums[j];
        } else if (k > order) {
            return select(nums, j + 1, right, k - order);
        } else {
            return select(nums, left, j - 1, k);
        }
    }
    int partition(vector<int>& nums, int left, int right) {
        int val = nums[left];
        int i = left;
        int j = right + 1;
        //my partition puts elements larger than val to the left
        //elements smaller than val to the right
        //this is different from normal partition
        while (true) {
            while (nums[++i] > val) {
                if (i == right) break;
            }
            while (nums[--j] < val) {
                if (j == left) break;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
            } else {
                swap(nums[left], nums[j]);
                return j;
            }
        }
    }
    void shuffle(vector<int>& nums) {
        int n = nums.size();
        for (int i = n - 1; i > 0; --i) {
            int j = random() % (i + 1);
            swap(nums[i], nums[j]);
        }
    }
};