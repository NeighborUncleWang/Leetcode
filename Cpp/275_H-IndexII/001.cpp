class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int low = 0;
        int high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;
            if (citations[mid] == n - mid) {
                return n - mid;
            } else if (citations[mid] > n - mid) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        //之所以选n - low 是因为low = high + 1
        //citations[low] >= n - low
        //citations[high] < n - high
        //low和high一定是一个让citations[index] >= n - index 满足
        //另一个让这个条件不满足。因为更大的index更容易满足上面的条件
        //所以应该是low满足条件，所以返回n - low
        return n - low;
    }
};