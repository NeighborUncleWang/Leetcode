class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        vector<int> leftMax(n, 0), rightMin(n, 0);
        int maxNum = 0, minNum = 9;
        for (int i = 0; i < n; ++i) {
            maxNum = max(maxNum, arr[i]);
            leftMax[i] = maxNum;
        }
        for (int i = n - 1; i >= 0; --i) {
            minNum = min(minNum, arr[i]);
            rightMin[i] = minNum;
        }
        int cut = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (leftMax[i] < rightMin[i + 1]) {
                ++cut;
            }
        }
        return cut + 1;
    }
};
