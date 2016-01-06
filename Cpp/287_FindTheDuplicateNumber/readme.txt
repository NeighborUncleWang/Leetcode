001.cpp:
Time complexity: O(n)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation
https://en.wikipedia.org/wiki/Cycle_detection#Tortoise_and_hare
这个问题里nums[x0]就相当于f(x0)
对于linkedlist找cycle问题next(head)就相当于f(x0)
slow和fast不能初始化为0，否则一开始就相等第一个while loop就不执行了
002.cpp:
Time complexity: O(nlogn)
Space complexity: O(1)
Reference:
https://leetcode.com/discuss/60830/solutions-explanation-space-without-changing-input-array