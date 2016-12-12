/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        int index = 0;
        if (s[0] == '[') {
            return ParseList(s, ++index);
        } else {
            return ParseNumber(s, index);
        }
    }
private:
    NestedInteger ParseList(string& s, int& index) {
        NestedInteger result;
        while (index < s.size()) {
            if (s[index] == '[') {
                result.add(ParseList(s, ++index));
            } else if (s[index] == '-' || isdigit(s[index])) {
                result.add(ParseNumber(s, index));
            } else if (s[index] == ',') {
                ++index;
            } else if (s[index] == ']') {
                ++index;
                return result;
            }
        }
        return result;
    }
    NestedInteger ParseNumber(string& s, int& index) {
        int temp = index;
        while (isdigit(s[index]) || s[index] == '-') {
            ++index;
        }
        return NestedInteger(stoi(s.substr(temp, index - temp)));
    }
};