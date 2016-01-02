class NumArray {
private:
    vector<int> accumulation;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        accumulation = vector<int>(n + 1, 0);
        for (int i = 1; i < n + 1; ++i) {
            accumulation[i] = accumulation[i - 1] + nums[i - 1];
        }
    }

    int sumRange(int i, int j) {
        return accumulation[j + 1] - accumulation[i];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);