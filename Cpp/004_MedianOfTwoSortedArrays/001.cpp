class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        return (SplitMerge(nums1, 0, n1, nums2, 0, n2, (n1 + n2 - 1) / 2)
                + SplitMerge(nums1, 0, n1, nums2, 0, n2, (n1 + n2) / 2)) / 2.0;
    }
    int SplitMerge(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {
        int n1 = end1 - start1;
        int n2 = end2 - start2;
        if (n1 > n2) {
            return SplitMerge(nums2, start2, end2, nums1, start1, end1, k);
        }
        if (n1 == 0) {
            return nums2[start2 + k];
        }
        if (k == 0) {
            return min(nums1[start1], nums2[start2]);
        }
        int p1 = min(k / 2, n1 - 1);
        int p2 = k - p1 - 1;
        if (nums1[start1 + p1] == nums2[start2 + p2]) {
            return nums1[start1 + p1];
        } else if (nums1[start1 + p1] < nums2[start2 + p2]) {
            return SplitMerge(nums1, start1 + p1 + 1, end1, nums2, start2, end2, k - p1 - 1);
        } else {
            return SplitMerge(nums1, start1, end1, nums2, start2 + p2 + 1, end2, k - p2 - 1);
        }
    }
};
