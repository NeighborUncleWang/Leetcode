class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> heap(less<int>(), nums);
        int result = 0;
        for (int i = 0; i < k; ++i) {
            result = heap.top();
            heap.pop();
        }
        return result;
    }
};
