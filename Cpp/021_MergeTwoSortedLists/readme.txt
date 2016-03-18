001.cpp:
Time complexity: O(min(n1, n2))
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/18986/14-line-clean-c-solution
这题不要用wikipedia上merge sort的方法，因为那个方法时间复杂度是O(n1 + n2),这个方法是O(min(n1, n2)).