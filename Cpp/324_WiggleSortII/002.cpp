class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end(), greater<int>());
        //关于怎么计算large和small：
        //要保证small numbers >= large numbers
        //因为数组下标从0开始，所以number of even indices >= number of odd indices
        //然后保证nums.size()为奇数或者偶数时small一直不少于large就行
        //这题不能把nums排成ascending order然后small = 0, large = (nums.size() + 1) / 2
        //那样会存在两个medium相邻的情况
        //比如input[4,5,5,6]会输出[4,5,5,6]
        //因为如果按照desending的方法排序nums
        //median的值可以保证在nums最两端
        //但是如果按照ascending的方法排序nums
        //当nums size为偶数时，median会在index = 1 , nums.size() - 2的地方
        //所以不能保证median的值离得最远
        int large = 0;
        int small = nums.size() / 2;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = (i % 2) ? sorted[large++] : sorted[small++];
        }
    }
};