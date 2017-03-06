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
            //这里之所以要检查position == 0是因为
            //当node != "#"的时候，虽然是++position
            //但是其实是--position;position += 2;两条语句顺序执行的效果
            //所以进loop的时候要检查position == 0
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