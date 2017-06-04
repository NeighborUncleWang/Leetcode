class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums.back()) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        if (low == n) return -1;
        int min_index = low;
        if (nums.back() >= target) {
            low = min_index;
            high = n - 1;
        } else {
            low = 0;
            high = min_index - 1;
        }
        // 或者根据reference里的写成这样:
        // int rot=min_index;
        // lo=0;hi=n-1;
        // // The usual binary search and accounting for rotation.
        // while(lo<=hi){
        //     int mid=(lo+hi)/2;
        //     int realmid=(mid+rot)%n;
        //     if(A[realmid]==target)return realmid;
        //     if(A[realmid]<target)lo=mid+1;
        //     else hi=mid-1;
        // }
        // return -1;
        // 因为min_index本来应该是0，现在变成了min_index;
        // 所以相当于所有元素都被右移了min_index
        // binary search里mid需要加上min_index才能真实反映这个位置
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1; 
    }
};