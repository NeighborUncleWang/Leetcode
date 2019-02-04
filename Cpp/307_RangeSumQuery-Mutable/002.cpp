class NumArray {
private:
    vector<int> nums;
    int size;
    vector<int> BIT;
    //还是单独写一个updateBIT()
    //不要直接在update()函数里写逻辑
    //否则容易出错
    //感觉必须放在外面，因为constructor必须call updateBIT的样子
    void updateBIT(int index, int diff) {
        ++index;
        while (index <= size) {
            BIT[index] += diff;
            index += index & -index;
        }
    }
    int getSum(int index) {
        //之所以update和getSum之前都要index++
        //是因为BIT的实现中是假设数组第一个元素index为1而不是0
        ++index;
        int sum = 0;
        //这里不能用 index >= 0
        //否则这个while loop就陷入死循环了
        while (index > 0) {
            sum += BIT[index];
            index -= index & -index;
        }
        return sum;
    }
public:
    NumArray(vector<int> nums) {
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
