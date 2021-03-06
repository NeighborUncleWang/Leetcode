class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int minDistance = INT_MAX;
        bool isSame = word1 == word2;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                index1 = i;
            }
            if (words[i] == word2) {
                if (isSame) {
                    index1 = index2;
                }
                index2 = i;
            }
            if (index1 >= 0 && index2 >= 0) {
                minDistance = min(minDistance, abs(index1 - index2));
            }
        }
        return minDistance;
    }
};