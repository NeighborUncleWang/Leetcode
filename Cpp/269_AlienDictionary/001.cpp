class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> successor;
        unordered_map<char, unordered_set<char>> predecessor;
        unordered_set<char> chars;
        //construct the graph
        string previousString;
        for (string currentString : words) {
            chars.insert(currentString.begin(), currentString.end());
            for (int i = 0; i < min(previousString.size(), currentString.size()); ++i) {
                char currentChar = currentString[i];
                char previousChar = previousString[i];
                if (currentChar != previousChar) {
                    predecessor[currentChar].insert(previousChar);
                    successor[previousChar].insert(currentChar);
                    break;
                }
            }
            previousString = move(currentString);
        }
        queue<char> nodesQueue;
        for (char ci : chars) {
            if (predecessor.find(ci) == predecessor.end()) {
                nodesQueue.push(ci);
            }
        }
        string order;
        while (!nodesQueue.empty()) {
            auto node = nodesQueue.front();
            nodesQueue.pop();
            order.push_back(node);
            for (char ch : successor[node]) {
                predecessor[ch].erase(node);
                if (predecessor[ch].empty()) {
                    nodesQueue.push(ch);
                }
            }
        }
        return order.size() == chars.size() ? order : "";
    }
};