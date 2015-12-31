class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string>> hashMap;
        for (string& s : strings) {
            hashMap[shiftFeature(s)].push_back(s);
        }
        vector<vector<string>> groups;
        for (auto& i : hashMap) {
            sort(i.second.begin(), i.second.end());
            groups.push_back(i.second);
        }
        return groups;
    }
private:
    string shiftFeature(string& s) {
        string result;
        for (int i = 1; i < s.size(); ++i) {
            int difference = s[i] - s[i - 1];
            difference += difference < 0 ? 26 : 0;
            result += difference;
        }
        return result;
    }
};