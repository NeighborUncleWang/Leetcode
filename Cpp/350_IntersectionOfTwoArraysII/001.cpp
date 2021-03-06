class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for (int num : nums1) {
            ++count[num];
        }
        vector<int> result;
        for (int num : nums2) {
            if (count.count(num) != 0 && count[num]-- > 0) {
                result.push_back(num);
            }
        }
        return result;
    }
};