class Solution {
private:
    vector<int> sums;
public:
    Solution(vector<int> w) {
        int sum = 0;
        sums.push_back(0);
        for (int weight : w) {
            sum += weight;
            sums.push_back(sum);
        }
    }

    int pickIndex() {
        int idx = rand() % sums.back();
        return upper_bound(sums.begin(), sums.end(), idx) - sums.begin() - 1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(w);
 * int param_1 = obj.pickIndex();
 */
