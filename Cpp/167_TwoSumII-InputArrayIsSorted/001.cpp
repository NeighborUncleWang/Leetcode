class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = (int)numbers.size() - 1;
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return vector<int>{left + 1, right + 1};
            } else if (sum < target) {
                //因为[left, right - 1], [left, right - 2]这些pair的sum都会小于target
                //不符合要求，所以要++left寻找新的pair
                //下面的--right同理
                ++left;
            } else if (sum > target) {
                --right;
            }
        }
        return vector<int>{-1, -1};
    }
};