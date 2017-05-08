001.cpp:
Time complexity: O(m*n)
Space complexity: O(m + n)
即使不用vector<int> rows来存每行‘B’的数目，也需要O(m + n)space
所以这个优化意义不大
Reference:
https://discuss.leetcode.com/topic/81686/verbose-java-o-m-n-solution-hashmap
https://discuss.leetcode.com/topic/81696/o-mn-concise-solution-c