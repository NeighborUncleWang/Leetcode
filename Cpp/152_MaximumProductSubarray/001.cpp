class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProductEndsHere = nums[0];
        int minProductEndsHere = nums[0];
        int maxProduct = nums[0];
        for (int i = 1; i < nums.size(); ++ i) {
            int temp = maxProductEndsHere;
            maxProductEndsHere = max({maxProductEndsHere * nums[i], nums[i], minProductEndsHere * nums[i]});
            minProductEndsHere = min({temp * nums[i], nums[i], minProductEndsHere * nums[i]});
            maxProduct = max(maxProduct, maxProductEndsHere);
        }
        return maxProduct;
    }
};