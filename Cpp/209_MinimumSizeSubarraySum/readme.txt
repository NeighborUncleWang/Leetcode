001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Use two pointers to maintain the size of the subarray that sums upto s.
Reference:
https://leetcode.com/discuss/45449/accepted-clean-java-o-n-solution-two-pointers
002.cpp：
Time complexity: O(nlogn)
Space complexity: O(n)
Use binary search to find head of the subarray for each tail range from 0 to n - 1.
Reference:
https://leetcode.com/discuss/35378/solutions-java-with-time-complexity-nlogn-with-explanation
Another much shorter binary search one:
https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c/10
代码里可以没有这行：
if (p != sums.end()) 
但是必须要有if (sums[i] >= s)
003.cpp：
Time complexity: O(nlogn)
Space complexity: O(n)
My solution for the binary search approach.