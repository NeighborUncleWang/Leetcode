class NumArray {
private:
    //accumulation[i] stores sum of [0, i)
    vector<int> accumulation;
public:
    NumArray(vector<int> &nums) {
        int n = nums.size();
        accumulation = vector<int>(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            accumulation[i + 1] = accumulation[i] + nums[i];
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