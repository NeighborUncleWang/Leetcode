class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int result = 0;
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int left = it == heaters.begin() ? INT_MAX : (house - *(it - 1));
            int right = it == heaters.end() ? INT_MAX : (*it - house);
            result = max(result, min(left, right));
        }
        return result;
    }
};