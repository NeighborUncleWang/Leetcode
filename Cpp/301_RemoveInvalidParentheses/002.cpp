class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        queue<string> nodesQueue;
        nodesQueue.push(s);
        vector<string> result;
        unordered_set<string> visited;
        bool found = false;
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                string node = nodesQueue.front();
                nodesQueue.pop();
                if (isValid(node)) {
                    result.push_back(node);
                    found = true;
                }
                //actually we can use result.empty() as found
                if (!found) {
                    for (int i = 0; i < node.size(); ++i) {
                        if (node[i] == '(' || node[i] == ')') {
                            string temp = node.substr(0, i) + node.substr(i + 1);
                            if (visited.find(temp) == visited.end()) {
                                nodesQueue.push(temp);
                                visited.insert(move(temp));
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
private:
    bool isValid(string &s) {
        int leftParenthesis = 0;
        for (char ch : s) {
            if (ch == '(') {
                ++leftParenthesis;
            } else if (ch == ')') {
                if (--leftParenthesis == -1) {
                    return false;
                }
            }
        }
        return leftParenthesis == 0;
    }
};