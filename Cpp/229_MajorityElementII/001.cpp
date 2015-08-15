class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = 0;
        int num2 = 0;
        int count1 = 0;
        int count2 = 0;
        vector<int> result;
        for (int i = 0; i< nums.size(); ++i) {
            if (count1 == 0) {
                num1 = nums[i];
                count1 = 1; 
            } else if (count2 == 0 && num1 != nums[i]) {
                num2 = nums[i];
                count2 = 1;
            } else if (nums[i] == num1) {
                ++count1;
            } else if (nums[i] == num2) {
                ++count2;
            } else {
                --count1;
                --count2;
            }
        }
        if (verifyMajority(num1, nums)) {
            result.push_back(num1);
        }
        //num2还是有可能等于num1,比如nums = [0, 0, 0]的时候
        if (verifyMajority(num2, nums) && num2 != num1) {
            result.push_back(num2);
        }
        return result;
    }
private:
    bool verifyMajority(int number, vector<int>& nums) {
        int count = 0;
        for (auto i : nums) {
            if (i == number) {
                ++count;
            }
        }
        return count > nums.size() / 3;
    }
};
