class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, function<bool(int, int)>> heap(greater<int>{});
        for (int num : nums) {
            heap.push(num);
            if (heap.size() > k) {
                heap.pop();
            }
        }
        return heap.top();
    }
};