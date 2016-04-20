/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    int depthSum(vector<NestedInteger>& nestedList) {
        queue<NestedInteger> nodesQueue;
        for (NestedInteger& node : nestedList) {
            nodesQueue.push(node);
        }
        int level = 1;
        int sum = 0;
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                NestedInteger current = nodesQueue.front();
                nodesQueue.pop();
                if (current.isInteger()) {
                    sum += current.getInteger() * level;
                } else {
                    for (NestedInteger& node : current.getList()) {
                        nodesQueue.push(node);
                    }
                }
            }
            ++level;
        }
        return sum;
    }
};