001.cpp:
Time complexity: O(n)
Space complexity: O(n)
其实用unordered_set<pair<int, int>>存储空间也不见得比unordered_map<int, unordered_set<int>>小，因为前者每个point都要用掉8bytes，后者大部分point都只用掉4bytes。
Reference:
https://discuss.leetcode.com/topic/48172/simple-java-hashset-solution