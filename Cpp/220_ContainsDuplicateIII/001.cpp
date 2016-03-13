class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        //distinct number so k >= 1
        if (k < 1 || t < 0) return false;
        unordered_map<long long, long long> hashMap;
        for (int i = 0; i < nums.size(); ++i) {
            long long reposition = (long long)nums[i] - INT_MIN;
            long long bucketIndex = reposition / ((long long)t + 1);
            if (hashMap.find(bucketIndex) != hashMap.end()
            || hashMap.find(bucketIndex - 1) != hashMap.end() && reposition - hashMap[bucketIndex - 1] <= t
            || hashMap.find(bucketIndex + 1) != hashMap.end() && hashMap[bucketIndex + 1] - reposition <= t) {
                return true;
            }
            hashMap[bucketIndex] = reposition;
            if (hashMap.size() > k) {
                hashMap.erase(((long long)nums[i - k] - INT_MIN) / ((long long)t + 1));
            }
        }
        return false;
    }
};