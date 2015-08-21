class Solution {
private:
    struct Node {
        enum NodeType {Left, Right};
        int xPosition;
        int height;
        NodeType type;
        Node(int xPosition, int height, NodeType type) : xPosition(xPosition), height(height),
        type(type) {}
    };
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int> heights;
        vector<Node> positions;
        vector<pair<int, int>> result;
        for (auto &i : buildings) {
            //这里因为NodeType在Node类内部，所以Left前面要加scope operator
            //如果NodeType在Solution内部Node类外部或者直接在Solution外部，都不需要叫scope operator
            //这说明在类里面定义的函数默认能取到的范围是和他平行都在Solution类内部的element，
            //或者比它高一级外面的区域
            positions.push_back(Node(i[0], i[2], Node::Left));
            positions.push_back(Node(i[1], i[2], Node::Right));
        }
        sort(positions.begin(), positions.end(), [](Node& lhs, Node& rhs) {
            if (lhs.xPosition != rhs.xPosition) {
                return lhs.xPosition < rhs.xPosition;
            } else {
                if (lhs.type != rhs.type) {
                    return lhs.type == Node::Left;
                } else if (lhs.type == Node::Left) {
                    return lhs.height > rhs.height;
                } else {
                    return lhs.height < rhs.height;
                }
            }
        });
        heights.insert(0);
        int previous = 0;
        int current = 0;
        for (auto &i : positions) {
            if (i.type == Node::Left) {
                heights.insert(i.height);
            } else {
                heights.erase(heights.find(i.height));
            }
            current = *heights.rbegin();
            if (current != previous) {
                result.push_back(pair<int, int>{i.xPosition, current});
                previous = current;
            }
        }
        return result;
    }
};
