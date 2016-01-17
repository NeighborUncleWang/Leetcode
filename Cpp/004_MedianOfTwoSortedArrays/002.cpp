class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        if (n2 == 0) {
            return (nums1[(n1 - 1) / 2] + nums1[n1 / 2]) / 2.0;
        }
        int low = 0;
        int high = 2 * n2;
        while (low <= high) {
            int middle2 = low + (high - low) / 2;
            int middle1 = n1 + n2 - middle2;
            int L1 = middle1 == 0 ? INT_MIN : nums1[(middle1 - 1) / 2];
            int R1 = middle1 == 2 * n1 ? INT_MAX : nums1[middle1 / 2];
            int L2 = middle2 == 0 ? INT_MIN : nums2[(middle2 - 1) / 2];
            int R2 = middle2 == 2 * n2 ? INT_MAX : nums2[middle2 / 2];
            if (L1 > R2) {
                low = middle2 + 1;
            } else if (L2 > R1) {
                high = middle2 - 1;
            } else {
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            }
        }
        return -1;
    }
};