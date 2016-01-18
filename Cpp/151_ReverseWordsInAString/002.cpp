class Solution {
public:
    void reverseWords(string &s) {
        stringstream ss(s);
        string result;
        string word;
        while (ss >> word) {
            result = word + " " + result;
        }
        s = result.substr(0, result.size() - 1);
    }
};