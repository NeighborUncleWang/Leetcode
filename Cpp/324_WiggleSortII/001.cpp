class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        shuffle(nums);
        int size = nums.size();
        //slect the (size / 2 + 1)th element
        //实际上c++有nth_element这个函数，不过这里我自己实现了一下
        int median = selection(nums, 0, size - 1, size / 2 + 1);
        auto virtualIndex = [size](int i) { return (2 * i + 1) % (size | 1); };
        int small = 0;
        int middle = 0;
        int large = size - 1;
        while (middle <= large) {
            if (nums[virtualIndex(middle)] > median) {
                swap(nums[virtualIndex(small++)], nums[virtualIndex(middle++)]);
            } else if (nums[virtualIndex(middle)] < median) {
                swap(nums[virtualIndex(middle)], nums[virtualIndex(large--)]);
            } else {
                ++middle;
            }
        }
    }
private:
    void shuffle(vector<int>& nums) {
        int size = nums.size();
        for (int i = size - 1; i > 0; --i) {
            int j = rand() % (i + 1);
            swap(nums[i], nums[j]);
        }
    }
    int selection(vector<int>& nums, int start, int end, int k) {
        if (start == end) {
            return nums[start];
        }
        int pivotIndex = partition(nums, start, end);
        int order = pivotIndex - start + 1;
        if (order == k) {
            return nums[pivotIndex];
        } else if (order < k) {
            return selection(nums, pivotIndex + 1, end, k - order);
        } else {
            return selection(nums, start, pivotIndex - 1, k);
        }
    }
    int partition(vector<int>& nums, int start, int end) {
        int val = nums[end];
        int i = start - 1;
        for (int j = start; j < end; ++j) {
            if (nums[j] <= val) {
                swap(nums[++i], nums[j]);
            }
        }
        swap(nums[i + 1], nums[end]);
        return i + 1;
    }
};