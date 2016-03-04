class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end(), greater<int>());
        //关于怎么计算large和small：
        //要保证small numbers >= large numbers
        //因为数组下标从0开始，所以number of even indices >= number of odd indices
        //然后保证nums.size()为奇数或者偶数时small一直不少于large就行
        int large = 0;
        int small = nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = (i % 2) ? sorted[large++] : sorted[small++];
        }
    }
};