class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int nums1Size = nums1.size();
        int nums2Size = nums2.size();
        vector<int> result;
        for (int k1 = max(k - nums2Size, 0); k1 <= nums1Size && k1 <= k; ++k1) {
            result = max(result,
                         merge(maxNumberSingleArray(nums1, k1), maxNumberSingleArray(nums2, k - k1)));
        }
        return result;
    }
private:
    vector<int> merge(vector<int> nums1, vector<int> nums2) {
        auto it1 = nums1.begin();
        auto it2 = nums2.begin();
        auto end1 = nums1.end();
        auto end2 = nums2.end();
        vector<int> result;
        while (it1 != end1 || it2 != end2) {
            result.push_back(lexicographical_compare(it1, end1, it2, end2) ? *it2++ : *it1++);
        }
        return result;
    }
    vector<int> maxNumberSingleArray(vector<int>& nums, int k) {
        int numsSize = nums.size();
        //use the vector<int> as a stack
        vector<int> result(k);
        for (int i = 0, stackSize = 0; i < numsSize; ++i) {
            while (numsSize - i + stackSize > k && stackSize > 0 && result[stackSize - 1] < nums[i]) {
                --stackSize;
            }
            if (stackSize < k) {
                result[stackSize++] = nums[i];
            }
        }
        result;
        return result;
    }
};