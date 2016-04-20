001.cpp:
Time complexity:
next(): O(1)
hasNext(): O(1)(amortized O(1))
Space comoplexity: O(n)
对stefan的方法进行了改进，把每个vector<NestedIntger>的iterator存到一个pair里.
Reference:
https://leetcode.com/discuss/95934/real-iterator-in-python-java-c