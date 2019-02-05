class Solution {
private:
    vector<int> nums, BIT;
    int sum = 0;
    void updateBIT(int i, int val) {
        ++i;
        while (i <= nums.size()) {
            BIT[i] += val;
            i += i & -i;
        }
    }
    int getSum(int index) {
        ++index;
        int res = 0;
        while (index > 0) {
            res += BIT[index];
            index -= index & -index;
        }
        return res;
    }
public:
    Solution(vector<int> w) {
        nums = vector<int>(w.size(), 0);
        BIT = vector<int>(w.size() + 1, 0);
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            updateBIT(i, w[i]);
        }
        nums = w;
    }

    int pickIndex() {
        int target = rand() % sum;
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (getSum(mid) > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
