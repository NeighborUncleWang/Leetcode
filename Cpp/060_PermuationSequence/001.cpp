class Solution {
public:
    string getPermutation(int n, int k) {
        if (n <= 0) {
            return "";
        }
        --k;
        int factorial = 1;
        for (int i = 2; i < n; ++i) {
            factorial *= i;
        }
        vector<int> nums(n);
        for (int i = 0; i < n; ++i) {
            nums[i] = i + 1;
        }
        string result;
        while (nums.size() > 0) {
            int index = k / factorial;
            k %= factorial;
            result.push_back(nums[index] + '0');
            if (n - 1 > 0)
                factorial /= n - 1;
            --n;
            nums.erase(nums.begin() + index);
        }
        return result;
    }
};
