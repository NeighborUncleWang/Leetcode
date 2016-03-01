class Solution {
public:
    bool isValidSerialization(string preorder) {
        vector<string> nodes;
        stringstream ss(preorder);
        string node;
        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }
        int position = 1;
        for (string& node : nodes) {
            if (position == 0) return false;
            if (node == "#") {
                --position;
            } else {
                ++position;
            }
        }
        return position == 0;
    }
};