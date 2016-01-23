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
        //因为index有可能为0，然后如果一个char或者word没被初始化在
        //hashmap里value也为0
        pattern2index[pattern[i]] = word2index[word] = i + 1;
    }
    return i == n;
}
};