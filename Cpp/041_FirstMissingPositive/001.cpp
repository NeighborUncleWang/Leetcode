class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            //因为nums[i]swap完之后还要判断新的value是否满足条件
            //所以要用while语句
            //nums[nums[i] - 1]是看nums[i]应该在的位置有没有被nums[i]填充
            //不能判断nums[i] != i + 1
            //因为有可能整个nums不存在i + 1value
            //然后就死循环了
            while (nums[i] > 0 && nums[i] <= size
            && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < size; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return size + 1;
    }
};