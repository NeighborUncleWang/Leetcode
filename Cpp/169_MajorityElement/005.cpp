class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else {
                if (nums[i] == candidate) {
                    ++count;
                } else {
                    --count;
                }
            }
        }
        //since it mentions that there is always a majority element in the array
        //so we don't need to verify it
        return candidate;
    }
};
