001.cpp:
Time complexity: O(n)
Space complexity: O(1)
因为从左往右走，ascending order的序列每一个元素都应该比以前的max要大，如果比以前的max要小就说明是一个违规的元素。同理，从右往左走，ascending order的序列每一个元素都应该比以前的min要小，如果比以前的min要大就说明是一个违规的元素。
Reference:
https://discuss.leetcode.com/topic/89282/java-o-n-time-o-1-space
002.cpp:
Time complexity: O(nlogn)
Space complexity: O(n)
Sort.
Reference:
https://discuss.leetcode.com/topic/89300/java-solution-sort