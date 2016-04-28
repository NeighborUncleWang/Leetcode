class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        unordered_set<string> visited;
        wordList.insert(endWord);
        queue<string> nodesQueue;
        nodesQueue.push(beginWord);
        int length = 2;
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                string node = nodesQueue.front();
                nodesQueue.pop();
                for (int j = 0; j < node.size(); ++j) {
                    char temp = node[j];
                    //这里即使node没有改变(ch == temp)也没有关系
                    //因为原来node已经被标记成visited了
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        node[j] = ch;
                        if (wordList.find(node) != wordList.end() && visited.find(node) == visited.end()) {
                            if (node == endWord) {
                                return length;
                            }
                            visited.insert(node);
                            nodesQueue.push(node);
                        }
                    }
                    node[j] = temp;
                }
            }
            ++length;
        }
        return 0;
    }
};