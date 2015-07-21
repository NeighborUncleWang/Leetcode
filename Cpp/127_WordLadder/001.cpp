class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        queue<string> nodesQueue;
        unordered_set<string> graph;
        nodesQueue.push(beginWord);
        graph.insert(beginWord);
        int currentLevel = 1;
        int nextLevel = 0;
        int length = 1;
        while (nodesQueue.empty() == false) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            --currentLevel;
            if (node == endWord) {
                return length;
            }
            for (int i = 0; i < node.size(); ++i) {
                auto temp = node;
                for (char ch = 'a'; ch <= 'z'; ++ch) {
                    if (ch == temp[i]) {
                        continue;
                    }
                    temp[i] = ch;
                    //if (temp == endWord) {
                    //    return length + 1;
                    //}//atually this will have a bug if beginWord == endWord, if this case will not happen, then I think if I write my code here can save some time or we choose to iterate 26 letters instead of 25 letters to deal with this corner case
                    if (wordDict.find(temp) != wordDict.end() && graph.find(temp) == graph.end()) {
                        nodesQueue.push(temp);
                        ++nextLevel;
                        graph.insert(temp);
                    }
                }
            }
            if (currentLevel == 0) {
                currentLevel = nextLevel;
                nextLevel = 0;
                ++length;
            }
        }
        return 0;
    }
};
