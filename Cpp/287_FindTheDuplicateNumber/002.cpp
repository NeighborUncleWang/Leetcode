class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1;
        int high = nums.size() - 1;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            int count = 0;
            for (int i : nums) {
                if (i <= middle) {
                    ++count;
                }
            }
            if (count > middle) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }
};