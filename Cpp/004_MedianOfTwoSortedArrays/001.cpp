class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if ((n + m) & 1 == 1) {
            return helper(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2 + 1);
        } else {
            return (helper(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2)
            + helper(nums1, 0, m - 1, nums2, 0, n - 1, (m + n) / 2 + 1)) * 1.0 / 2;
        }
    }
private:
    double helper(vector<int>& nums1, int start1, int end1,
    vector<int>& nums2, int start2, int end2, int k) {
        int m = end1 - start1 + 1;
        int n = end2 - start2 + 1;
        //assume m <= n
        if (m > n) {
            return helper(nums2, start2, end2, nums1, start1, end1, k);
        }
        if (m == 0) {
            return nums2[start2 + k - 1];
        }
        if (k == 1) {
            return min(nums1[start1], nums2[start2]);
        }
        int p1 = min(k / 2, m);
        int p2 = k - p1;
        if (nums1[start1 + p1 - 1] == nums2[start2 + p2 - 1]) {
            return nums1[start1 + p1 - 1];
        } else if (nums1[start1 + p1 - 1] < nums2[start2 + p2 - 1]) {
            // remove the lower part of nums1 and upper part of nums2
            //虽然移走两部分，但是k只受移走的lower part的影响，所以是k - p1 instead of k - p1 - p2
            return helper(nums1, start1 + p1, end1, nums2, start2, start2 + p2 - 1, k - p1);
        } else {
            // remove the lower part of nums2 and upper part of nums1
            return helper(nums1, start1, start1 + p1, nums2, start2 + p2, end2, k - p2);
        }
    }
};
