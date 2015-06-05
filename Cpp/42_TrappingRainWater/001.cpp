class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }
        vector<int> maxLeft(n);
        vector<int> maxRight(n);
        maxLeft[0] = 0;
        int max = 0;
        for (int i = 0; i < n; ++i) {
            maxLeft[i] = max;
            if (height[i] > max) {
                max = height[i];
            }
        }
        max = 0;
        maxRight[n - 1] = 0;
        int sum = 0;
        int capability;
        for (int i = n - 1; i >= 0; --i) {
            maxRight[i] = max;
            capability = min(maxRight[i], maxLeft[i]) - height[i];
            if (capability > 0) {
                sum += capability ;
            }
            if (height[i] > max) {
                max = height[i];
            }
        }
        return sum;
    }
};
