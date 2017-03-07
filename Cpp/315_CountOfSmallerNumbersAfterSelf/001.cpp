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
        splitMerge(nums, 0, numsSize, indices, result);
        return result;
    }
private:
    //end is exclusive [start, end)
    void splitMerge(vector<int>& nums, int start, int end, vector<int>& indices, vector<int>& result) {
        //这里必须是<2，<1不行，会run time error，
        //因为start = 0, mid = 0, end = 1会导致无穷递归
        if (end - start < 2) {
            return;
        }
        int middle = start + (end - start) / 2;
        splitMerge(nums, start, middle, indices, result);
        splitMerge(nums, middle, end, indices, result);
        merge(nums, start, middle, end, indices, result);
    }
    void merge(vector<int>& nums, int start, int middle, int end, vector<int>& indices, vector<int>& result) {
        int length = end - start;
        vector<int> tempIndices;
        int index1 = start;
        int index2 = middle;
        int rightCount = 0;
        //when we sort the elements, we should sort their indices in the original nums vector
        //so that we can update the corresponding value in the result vector
        //唯一要用到的就是nums[indices[index1]] <= nums[indices[index2]]这里
        //其他地方都用不到nums，都是对原来的indices进行操作
        while (index1 < middle || index2 < end) {
            //这里必须是nums[indices[index1]] <= nums[indices[index2]]
            //不能是nums[indices[index1]] < nums[indices[index2]]
            if (index1 < middle && (index2 >= end || nums[indices[index1]] <= nums[indices[index2]])) {
                tempIndices.push_back(indices[index1]);
                //这里必须是 += rightCount, 而不是 = rightCount;
                //因为两个subarray merge之前result已经存有两个subarray里的reverse数值了
                result[indices[index1]] += rightCount;
                ++index1;
            } else {
                tempIndices.push_back(indices[index2]);
                ++index2;
                ++rightCount;
            }
        }
        move(tempIndices.begin(), tempIndices.end(), indices.begin() + start);
    }
};