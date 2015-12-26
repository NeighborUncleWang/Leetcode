class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int numsSize = nums.size();
        vector<int> indices(numsSize, 0);
        for (int i = 0; i < numsSize; ++i) {
            indices[i] = i;
        }
        vector<int> result(numsSize, 0);
        splitMerge(nums, 0, numsSize, indices, result);
        return result;
    }
private:
    //end is exclusive [start, end)
    void splitMerge(vector<int>& nums, int start, int end, vector<int>& indices, vector<int>& result) {
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
            //we can also use the following test statement, it's from the wikipedia merge-sort
            //index1 < middle && (index2 >= end || nums[indices[index1]] <= nums[indices[index2]])
            if (index2 >= end || 
                (index1 < middle && nums[indices[index1]] <= nums[indices[index2]])) {
                tempIndices.push_back(indices[index1]);
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