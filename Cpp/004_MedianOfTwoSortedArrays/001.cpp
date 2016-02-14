class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size();
        int size2 = nums2.size();
        //这里用了一个trick
        //如果size1 + size2为奇数，那么这两个helper函数返回的值都是一样的
        //这样就不用奇数偶数分开讨论了
        return (helper(nums1, 0, size1, nums2, 0, size2, (size1 + size2) / 2 + 1)
        + helper(nums1, 0, size1, nums2, 0, size2, (size1 + size2 - 1) / 2 + 1)) / 2.0;
    }
private:
    int helper(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        //这里k就是指第几个数，如果k为1，代表第一个数，index对应是0
        int size1 = end1 - start1;
        int size2 = end2 - start2;
        if (size1 > size2) {
            return helper(nums2, start2, end2, nums1, start1, end1, k);
        }
        if (size1 == 0) {
            return nums2[start2 + k - 1];
        } else if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        //p1指的是nums1应该贡献多少个数
        //p2指的是nums2应该贡献多少个数
        //min(k / 2, size1)别忘了
        int p1 = min(k / 2, size1);
        int p2 = k - p1;
        int element1 = nums1[start1 + p1 - 1];
        int element2 = nums2[start2 + p2 - 1];
        if (element1 == element2) {
            return element1;
        } if (element1 < element2) {
            return helper(nums1, start1 + p1, end1, nums2, start2, end2, k - p1);
        } else {
            return helper(nums1, start1, end1, nums2, start2 + p2, end2, k - p2);
        }
    }
};