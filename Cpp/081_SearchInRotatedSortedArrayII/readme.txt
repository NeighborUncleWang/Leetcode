Problem Link:https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
001.cpp:
Time complexity : O(n)
Space complexity : O(1)
A simply modification from SearchInRotatedSortedArray. When nums[median] == nums[low], we just ++low to skip the duplicates. 
002.cpp:
Time complexity : O(n)
Space complexity : O(1)
Reference:
https://leetcode.com/discuss/223/when-there-are-duplicates-the-worst-case-is-could-we-do-better?show=230#a230
http://blog.csdn.net/linhuanmars/article/details/20588511