class Solution {
public:
   bool wordPattern(string pattern, string str) {
    map<char, int> pattern2index;
    map<string, int> word2index;
    stringstream in(str);
    int i = 0;
    int n = pattern.size();
    for (string word; in >> word; ++i) {
        if (i == n || pattern2index[pattern[i]] != word2index[word]) {
            return false;
        }
        //here must use i + 1
        //otherwise can't pass the case
        //"abba"
        //"dog cat cat fish"
        pattern2index[pattern[i]] = word2index[word] = i + 1;
    }
    return i == n;
}
};