class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), n = n1 + n2;
        //这里用了一个trick
        //如果size1 + size2为奇数，那么这两个helper函数返回的值都是一样的
        //这样就不用奇数偶数分开讨论了
        int res1 = helper(nums1, nums2, 0, n1, 0, n2, n / 2);
        int res2 = helper(nums1, nums2, 0, n1, 0, n2, n / 2 + n % 2 - 1);
        return (res1 + res2) / 2.0;
    }
private:
    int helper(vector<int>& nums1, vector<int>& nums2, int start1, int end1, int start2, int end2, int k) {
        //这里k就是指index，如果k为0，代表第一个数，index对应是0
        if (end1 - start1 > end2 - start2) {
            return helper(nums2, nums1, start2, end2, start1, end1, k);
        } else if (end1 - start1 == 0) {
            return nums2[start2 + k];
        } else if (k == 0) {
            return min(nums1[start1], nums2[start2]);
        }
        //p1指的是nums1应该贡献多少个数
        //p2指的是nums2应该贡献多少个数
        //min(k / 2, size1)别忘了
        //这里不能写成int p1 = (end1 + start1) / 2 - start1 + 1;
        //否则[1,2]，[3,4]这个case过不去
        //因为会造成p1 = 2, p2 = 0的情况
        //这时候mid2 = -1
        int p1 = min(end1 - start1,  (k + 1) / 2);
        int p2 = k + 1 - p1;
        int mid1 = start1 + p1 - 1;
        int mid2 = start2 + p2 - 1;
        if (nums1[mid1] == nums2[mid2]) {
            return nums1[mid1];
        } else if (nums1[mid1] < nums2[mid2]) {
            return helper(nums1, nums2, mid1 + 1, end1, start2, end2, k - p1);
        } else {
            return helper(nums1, nums2, start1, end1, mid2 + 1, end2, k - p2);
        }
    }
};