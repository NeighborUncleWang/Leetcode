class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        //left is the index of closest 1 at left
        int left = -1, n = seats.size(), res = 0;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (left == -1) {
                    res = max(res, i);
                } else {
                    res = max(res, (i - left) / 2);
                }
                left = i;
            }
        }
        return max(res, n - 1 - left);
    }
};
