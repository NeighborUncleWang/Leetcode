class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> successor;
        unordered_set<char> chars;
        //construct the graph
        string previousString;
        for (string currentString : words) {
            chars.insert(currentString.begin(), currentString.end());
            for (int i = 0; i < min(previousString.size(), currentString.size()); ++i) {
                char previousChar = previousString[i];
                char currentChar = currentString[i];
                if (previousChar != currentChar) {
                    successor[previousChar].insert(currentChar);
                    break;
                }
            }
            previousString = move(currentString);
        }
        int nodesNumber = chars.size();
        bool hasCycle = false;
        string order;
        unordered_map<char, Status> nodesStatus;
        for (char ch : chars) {
            nodesStatus[ch] = Unknown;
        }
        for (char ch : chars) {
            if (hasCycle) {
                return "";
            }
            if (nodesStatus[ch] == Unknown) {
                dfs(ch, nodesStatus, successor, hasCycle, order);
            }
        }
        reverse(order.begin(), order.end());
        return hasCycle ? "" : order;
    }
private:
    enum Status {
        Unknown,
        Discovered,
        Visited,
    };
    void dfs(char currentNode, unordered_map<char, Status>& nodesStatus,
    unordered_map<char, unordered_set<char>>& successor, bool& hasCycle, string& order) {
        nodesStatus[currentNode] = Discovered;
        for (char node : successor[currentNode]) {
            if (hasCycle) {
                break;
            }
            if (nodesStatus[node] == Unknown) {
                dfs(node, nodesStatus, successor, hasCycle, order);
            } else if (nodesStatus[node] == Discovered) {
                hasCycle = true;
                return;
            }
        }
        nodesStatus[currentNode] = Visited;
        order.push_back(currentNode);
    }
};