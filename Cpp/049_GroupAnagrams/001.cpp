class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashMap;
        for (string& s : strs) {
            string temp = s;
            sort(temp.begin(), temp.end());
            hashMap[temp].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& iter : hashMap) {
            sort(iter.second.begin(), iter.second.end());
            result.push_back(move(iter.second));
        }
        return result;
    }
};