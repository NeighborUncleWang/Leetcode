class Solution {
public:
    string frequencySort(string s) {
        vector<int> count(256, 0);
        for (char ch : s) {
            ++count[ch];
        }
        sort(s.begin(), s.end(), [&count](char a, char b) {
            return count[a] > count[b] || (count[a] == count[b] && a > b);
        });
        return s;
    }
};