class Solution {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        int index1 = -1;
        int index2 = -1;
        int minDistance = INT_MAX;
        for (int i = 0; i < words.size(); ++i) {
            if (words[i] == word1) {
                index1 = i;
                //这里写成if (index2 != -1)就能通过OJ了
                //因为index1一直是先于index2被更新的
                //所以只要words[i] == word2时检查index2 != index1就行了
                if (index2 != -1 && index2 != index1) {
                    minDistance = min(minDistance, abs(index2 - index1));
                }
            }
            if (words[i] == word2) {
                index2 = i;
                if (index1 != -1 && index2 != index1) {
                    minDistance = min(minDistance, abs(index1 - index2));
                }
            }
            //不能在最外层写一个statement否则["a","a"],"a","a"过不去
            // if (i1 != -1 && i2 != -1 && i1 != i2) {
            //     res = min(res, abs(i1 - i2));
            // }
        }
        return minDistance;
    }
};