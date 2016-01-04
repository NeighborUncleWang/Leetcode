// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1;
        int high = n;
        while (low <= high) {
            int middle = low + (high - low) / 2;
            if (isBadVersion(middle)) {
                high = middle - 1;
            } else {
                low = middle + 1;
            }
        }
        return low;
    }
};