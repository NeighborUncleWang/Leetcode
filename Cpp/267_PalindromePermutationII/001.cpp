class Solution {
public:
    vector<string> generatePalindromes(string s) {
        unordered_map<char, int> charCount;
        int odd = 0;
        for (char ch : s) {
            ++charCount[ch];
        }
        string middle = "";
        string chars;
        for (auto entry : charCount) {
            if (entry.second % 2) {
                ++odd;
                middle += entry.first;
            }
            //别用else，否则当s = "aaa"情况会出错
            chars.append(entry.second / 2, entry.first);
        }
        vector<string> result;
        if (odd > 1) {
            return result;
        }
        sort(chars.begin(), chars.end());
        vector<bool> used(chars.size(), false);
        string permutation;
        getPermutations(chars, permutation, middle, chars.size(), used, result);
        return result;
    }
private:
    void getPermutations(string& chars, string& permutation, 
    string& middle, int n, vector<bool>& used, vector<string>& result) {
        if (n == 0) {
            string temp = permutation;
            reverse(temp.begin(), temp.end());
            result.push_back(permutation + middle + temp);
            return;
        }
        for (int i = 0; i < chars.size(); ++i) {
            if (i > 0 && chars[i] == chars[i - 1] && !used[i - 1]) continue;
            if (used[i] == false) {
                used[i] = true;
                permutation.push_back(chars[i]);
                getPermutations(chars, permutation, middle, n - 1, used, result);
                permutation.pop_back();
                used[i] = false;
            }
        }
    }
};