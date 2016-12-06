class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            ++count[num];
        }
        priority_queue<pair<const int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
        for (auto it : count) {
            min_heap.push({it.second, it.first});
            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }
        vector<int> result;
        while (!min_heap.empty()) {
            result.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return result;
    }
};