class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> count;
        for (char ch : s) {
            ++count[ch];
        }
        vector<string> buckets(s.size() + 1);
        for (auto iter : count) {
            buckets[iter.second].append(iter.second, iter.first);
        }
        string result;
        for (int i = s.size(); i > 0; --i) {
            if (!buckets[i].empty()) {
                result += buckets[i];
            }
        }
        return result;
    }
};