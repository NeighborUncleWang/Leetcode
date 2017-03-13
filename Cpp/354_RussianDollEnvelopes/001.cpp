class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        //[3, 4] cannot contains [3, 3], 
        //so we need to put [3, 4] before [3, 3] 
        //when sorting otherwise it will be counted as an increasing number 
        //if the order is [3, 3], [3, 4]
        auto comp = [](pair<int, int> left, pair<int, int> right) {
            if (left.first < right.first) {
                return true;
            } else if (left.first == right.first) {
                return left.second > right.second;
            } else {
                return false;
            }
        };
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> result;
        for (auto envelope : envelopes) {
            auto it = lower_bound(result.begin(), result.end(), envelope.second);
            if (it == result.end()) {
                result.push_back(envelope.second);
            } else {
                *it = envelope.second;
            }
        }
        return result.size();
    }
};