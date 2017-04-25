001.cpp:
Time complexity: O(n^2)
Space complexity: O(1)
Reference:
因为player 1拿的数值算正，所以是nums[start] - helper(nums, start + 1, end, mem), nums[start]是正的, c++的解法不是很好，因为vector<vector<int*>>会导致memory leakage
可以把二维vector改成unordered_map<int, unordered_map<int, int>>,这样就能判断是否初始化过了
https://discuss.leetcode.com/topic/76312/java-1-line-recursion-solution

Wiki:
https://en.wikipedia.org/wiki/Minimax#Pseudocode