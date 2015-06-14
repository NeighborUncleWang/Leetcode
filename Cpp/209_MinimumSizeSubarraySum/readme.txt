001.cpp and 002.cpp:
Time complexity: O(n)
Space complexity: O(1)
Use two pointers to maintain the size of the subarray that sums upto s. 001.cpp is cleaner and shorter than 002.cpp.
003.cpp：
Time complexity: O(nlogn)
Space complexity: O(n)
Use binary search to find head of the subarray for each tail range from 0 to n - 1.
