class Solution {
private:
    bool valid(vector<int>& nums, int cut, long long max) {
        long long sum = 0;
        for (int num : nums) {
            sum += num;
            if (sum > max) {
                sum = num;
                if (--cut < 0) {
                    return false;
                }
            }
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        long long end = accumulate(nums.begin(), nums.end(), (long long)0);
        int start = *max_element(nums.begin(), nums.end());
        while (start <= end) {
            long long middle = start + (end - start) / 2;
            //m subarrays equals to m - 1 cuts
            if (valid(nums, m - 1, middle)) {
                end = middle - 1;
            } else {
                start = middle + 1;
            }
        }
        return start;
    }
};