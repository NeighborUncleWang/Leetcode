001.cpp:
Time complexity: O(nmk)(k is the number of strings)
Space complexity: O(mn)
Reference:
https://discuss.leetcode.com/topic/71438/c-dp-solution-with-comments
这题很像knapsack problem, 有0和1两个背包，每个背包容量分别为m和n，每个物品value为1
但是还是没想出来怎么从top left向bottom right update table,不知道这样可不可行
