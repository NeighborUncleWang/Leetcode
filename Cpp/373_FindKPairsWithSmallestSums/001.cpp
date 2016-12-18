class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if (nums1.empty() || nums2.empty()) return vector<pair<int, int>>();
        auto comp = [&nums1, &nums2] (pair<int, int> a, pair<int, int> b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> heap(comp);
        for (int i = 0; i < nums1.size() && i < k; ++i) {
            heap.emplace(i, 0);
        }
        vector<pair<int, int>> result;
        for (int i = 0; i < k && !heap.empty(); ++i) {
            auto top = heap.top();
            heap.pop();
            result.emplace_back(nums1[top.first], nums2[top.second]);
            if (++top.second < nums2.size()) {
                heap.push(top);
            }
        }
        return result;
    }
};