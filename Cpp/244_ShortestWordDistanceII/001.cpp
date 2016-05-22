class WordDistance {
private:
    unordered_map<string, vector<int>> wordIndex;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i < words.size(); ++i) {
            wordIndex[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int>& indices1 = wordIndex[word1];
        vector<int>& indices2 = wordIndex[word2];
        int n1 = indices1.size();
        int n2 = indices2.size();
        int minDistance = INT_MAX;
        for (int i1 = 0, i2 = 0; i1 < n1 && i2 < n2; ) {
            if (indices1[i1] < indices2[i2]) {
                //写在条件判断语句里面可以避免使用abs函数，
                //否则就像reference一样写在条件判断语句外面使用abs函数
                minDistance = min(minDistance, indices2[i2] - indices1[i1]);
                ++i1;
            } else {
                minDistance = min(minDistance, indices1[i1] - indices2[i2]);
                ++i2;
            }
        }
        return minDistance;
    }
};


// Your WordDistance object will be instantiated and called as such:
// WordDistance wordDistance(words);
// wordDistance.shortest("word1", "word2");
// wordDistance.shortest("anotherWord1", "anotherWord2");