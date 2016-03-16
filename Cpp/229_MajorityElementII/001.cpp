class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int candidate1 = 0;
        //这里要把candidate2初始化成!=candidate1
        //否则在最后result.push_back(candidate2)之前要检查
        //candidate1是否等于candidate2
        //否则[0，0，0]case通不过
        int candidate2 = 1;
        int counter1 = 0;
        int counter2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                ++counter1;
            } else if (num == candidate2) {
                ++counter2;
            } else if (counter1 == 0) {
                candidate1 = num;
                counter1 = 1;
            } else if (counter2 == 0) {
                candidate2 = num;
                counter2 = 1;
            } else {
                --counter1;
                --counter2;
            }
        }
        vector<int> result;
        if (count(nums.begin(), nums.end(), candidate1) > (nums.size() / 3)) {
            result.push_back(candidate1);
        }
        if (count(nums.begin(), nums.end(), candidate2) > (nums.size() / 3)) {
            result.push_back(candidate2);
        }
        return result;
    }
};