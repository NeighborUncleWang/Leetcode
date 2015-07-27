class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        int start = 0;//use int instead of size_t for convenience
        int end = numbers.size() - 1;
        while (start < end) {
            if (numbers[start] + numbers[end] == target) {
                result.push_back(start + 1);
                result.push_back(end + 1);
                return result;
            } else if (numbers[start] + numbers[end] > target) {
                --end;
            } else {
                ++start;
            }
        }
        return result;
    }
};
