class NumArray {
private:
    vector<int> nums;
    int size;
    vector<int> BIT;
    void updateBIT(int index, int diff) {
        ++index;
        while (index <= size) {
            BIT[index] += diff;
            index += index & -index;
        }
    }
    int getSum(int index) {
        ++index;
        int sum = 0;
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
public:
    NumArray(vector<int> &nums) {
        this->nums = nums;
        this->size = nums.size();
        BIT = vector<int>(size + 1, 0);
        for (int i = 0; i < size; ++i) {
            updateBIT(i, nums[i]);
        }
    }

    void update(int i, int val) {
        updateBIT(i, val - nums[i]);
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        return getSum(j) - getSum(i - 1);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);