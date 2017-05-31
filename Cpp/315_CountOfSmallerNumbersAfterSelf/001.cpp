class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> indices(numsSize, 0);
        iota(indices.begin(), indices.end(), 0);
        //iota相当于下面的功能
        // for (int i = 0; i < numsSize; ++i) {
        //     indices[i] = i;
        // }
        vector<int> result(numsSize, 0);
        Helper(nums, 0, numsSize, indices, result);
        return result;
    }
private:
    //end is exclusive [start, end)
    void Helper(vector<int>& nums, int start, int end, vector<int>& indices, vector<int>& result) {
        //这里必须是<2，<1不行，会run time error，
        //因为start = 0, mid = 0, end = 1会导致无穷递归
        if (end - start < 2) {
            return;
        }
        int mid = start + (end - start) / 2;
        Helper(nums, start, mid, indices, result);
        Helper(nums, mid, end, indices, result);
        vector<int> temp(end - start);
        int inversion = 0;
        //when we sort the elements, we should sort their indices in the original nums vector
        //so that we can update the corresponding value in the result vector
        //唯一要用到的就是nums[indices[i1]] <= nums[indices[i2]]这里
        //其他地方都用不到nums，都是对原来的indices进行操作
        for (int i = 0, i1 = start, i2 = mid; i < end - start; ++i) {
            //这里必须是nums[indices[i1]] <= nums[indices[i2]]
            //不能是nums[indices[i1]] < nums[indices[i2]]
            if (i1 < mid && (i2 == end || nums[indices[i1]] <= nums[indices[i2]])) {
                temp[i] = indices[i1];
                //这里必须是 += inversion, 而不是 = inversion;
                //因为两个subarray merge之前result已经存有两个subarray里的inversion数值了
                result[indices[i1]] += inversion;
                ++i1;
            } else {
                temp[i] = indices[i2];
                ++i2;
                ++inversion;
            }
        }
        move(temp.begin(), temp.end(), indices.begin() + start);
    }
};