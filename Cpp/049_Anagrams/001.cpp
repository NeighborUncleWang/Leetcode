class Solution {
public:
    vector<string> anagrams(vector<string>& strs) {
        vector<string> result;
        if (strs.size() == 0)
            return result;
        unordered_map<string, vector<string>> hashMap;
        for (int i = 0; i < strs.size(); ++i) {
            auto temp = strs[i];
            sort(temp.begin(), temp.end());//use the sorted strs[i] as a key
            hashMap[temp].push_back(strs[i]);
        }
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            if (it->second.size() > 1) {
                for (auto i : it->second) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};
