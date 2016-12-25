001.cpp:
Time complexity: O(n)
Space complexity: O(n)
第一个c++解法用了vector<int>(200)假设indent level不会超过200，这样不好，可以把这个vector换成hash_map
Reference:
https://discuss.leetcode.com/topic/55136/simple-c-o-n-solution-0ms
https://discuss.leetcode.com/topic/55247/9-lines-4ms-java-solution/2