001.cpp:
Time complexity: O(nlogn)
Space complexity: O(nlogn)
这题用到了经典divide-and-conquer问题count inversion的知识，kt算法书上有这个问题
divide-and-conquer 都可以学merge sort那样写成splitMerge + merge形式
References:
https://leetcode.com/discuss/74110/11ms-java-solution-using-merge-sort-with-explanation
https://en.wikipedia.org/wiki/Merge_sort
https://leetcode.com/discuss/73509/nlogn-time-space-mergesort-solution-with-detail-explanation
http://www.geeksforgeeks.org/counting-inversions/

002.cpp:
Time complexity: O(nlogn)
Space complexity: O(nlogn)
Idea is the same as 001.cpp. Use sorted vector to store both the value and the
original index of every element in nums.