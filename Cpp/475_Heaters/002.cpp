class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int i = 0;
        int result = 0;
        for (int house : houses) {
            while (i + 1 < heaters.size() && heaters[i + 1] + heaters[i] <= 2 * house) {
                ++i;
            }
            result = max(result, abs(house - heaters[i]));
        }
        return result;
    }
};