class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int size = nums.size();
        if (size < 2) return 0;
        int maxNum = *max_element(nums.begin(), nums.end());
        int minNum = *min_element(nums.begin(), nums.end());
        //因为maxGap>=(maxNum - minNum) / (size - 1)
        //然后bucketSize = (maxNum - minNum) / (size - 1)
        //所以在同一个bucket里面的数的gap<=(maxNum - minNum) / (size - 1) - 1
        //写成这样可以handle输入类型是double的情况
        //double bucketSize = max(numeric_limits<double>::min(), double(maxNum - minNum) / (double)(size - 1));
        //int bucketNum = size;
        int bucketSize = max(1, (maxNum - minNum) / (size - 1));
        int bucketNum = (maxNum - minNum) / bucketSize + 1;
        vector<vector<int>> buckets(bucketNum);
        for (int num : nums) {
            int index = (num - minNum) / bucketSize;
            if (buckets[index].size() == 0) {
                buckets[index].insert(buckets[index].end(), 2, num);
            } else {
                buckets[index][0] = min(buckets[index][0], num);
                buckets[index][1] = max(buckets[index][1], num);
            }
        }
        int previous = buckets[0][1];
        int maxGap = 0;
        for (int i = 1; i < bucketNum; ++i) {
            if (buckets[i].size() > 0) {
                maxGap = max(maxGap, buckets[i][0] - previous);
                previous = buckets[i][1];
            }
        }
        return maxGap;
    }
};